/*----------------------------------------------------------
 * LZ10 / LZ11 decompress library.
 * Programmed by RGBA_CRT 2019
 * referenced : https://problemkaputt.de/gbatek.htm
 * referenced : DSDecmp source
 *----------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "lz11.h"

#include <windows.h>
#include<stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    return TRUE;
}

uint32_t __stdcall lz11_getDecompressedSize(uint8_t *src, int32_t srcLen) {
	if ((srcLen > 4) && ((src[0] & 0xFE) == 0x10))
		return ((uint32_t *)src)[0] >> 8;

	else
		return 0;
}

LZ11_ERROR __stdcall lz11_decompress(uint8_t *src, uint32_t srcLen, uint8_t *dst, uint32_t dstLen, /* ByRef */ uint32_t *decompressedLen) {
	// ---- READ HEADER ----;
	// BYTE 0;	TYPE 10h / 11h;
	// BYTE 1-3; Decompressed Size;

	int32_t lzType;
	uint32_t header_dstSize;
	LZ11_ERROR error;
	error = LZ_OK;

	// 0バイト目はTYPE;
	lzType = src[0];
	if (lzType != 0x10 && lzType != 0x11) {
		error = LZ_UNKNOWN_FORMAT;
		goto LZD_ERR;
	}

	// 1-3バイト目は展開サイズ;
	header_dstSize = ((uint32_t *)src)[0] >> 8;

	// src/dst pointer;
	uint32_t src_p;
	uint32_t dst_p;
	src_p = 4;
	dst_p = 0;

	uint32_t flagbits;	// compressed/uncompressed flag bits
	int32_t len;	// dict length
	int32_t disp;	// dict pos	

	// 辞書パラメータを取りだして保存する変数
	uint32_t len_disp_bits;

	// len_disp_bitsのうち、下位12bitはdisp, それ以上12-32bitsはlen。
	// lenのビット数は変動する。src[0]の上位4bitが2以上, 1, 0で分岐する。

	while (1) {
		flagbits = src[src_p];
		src_p++;

		for (int bitloop = 0; bitloop < 8; bitloop++) {
			// EOB
			if (src_p >= srcLen) goto LZD_END;

			// check dst buffer overrun
			if (dstLen < dst_p) {
				error = LZ_BUFFER_ERROR;
				goto LZD_ERR;
			}

			// check MSB as flag of "compressed"
			flagbits = flagbits << 1;
			if ((flagbits & 0x100) == 0) {
				// uncompressed
				dst[dst_p] = src[src_p];
		//		printf("%x: %x[%c]\n",src_p, dst[dst_p], dst[dst_p]);

				dst_p++;
				src_p++;

			} else {
				// compressed

				// get len, disp parameter
				if (lzType == 0x10) {
					// pop 2 bytes as big endian.;
					len_disp_bits = (src[src_p] << 8) | (src[src_p + 1]);
					src_p += 2;

					// The additional byte is 3 in this case.;
					len = 3;

				} else if (lzType == 0x11) {
					switch (src[src_p] >> 4) {
					case 1:
						len_disp_bits = (src[src_p] << 24) | (src[src_p + 1] << 16) | (src[src_p + 2] << 8) | (src[src_p + 3]);
						src_p += 4;
						len = 0x111;
						break;

					case 0:
						len_disp_bits = (src[src_p] << 16) | (src[src_p + 1] << 8) | (src[src_p + 2]);
						src_p += 3;
						len = 0x11;
						break;

					default:
						len_disp_bits = (src[src_p] << 8) | (src[src_p + 1]);
						src_p += 2;
						len = 0x1;
						break;
					}
				}

				// common
				disp = (len_disp_bits & 0x0FFF) + 1;
				len += (len_disp_bits >> 12) & 0xFFFF;

				// check overrun
				if (dst_p < disp) {
					error = LZ_DATA_ERROR;	goto LZD_ERR;
				}
				if (dstLen < (dst_p + len)) {
					error = LZ_DATA_ERROR;	goto LZD_ERR;
				}

				// copy from dict
				// memcpy, memmoveを使うと、領域被りで期待した動作にならない。
				//memmove(&dst[dst_p], &dst[dst_p - disp], len);
				//dst_p += len;
				for(int i=0; i<len; i++){
					dst[dst_p] = dst[dst_p - disp];
					dst_p++;
				}
			}
		}
	}
LZD_END:
LZD_ERR:
	*decompressedLen = dst_p;
	return error;
}