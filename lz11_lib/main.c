/*----------------------------------------------------------
 * ActiveBasic to C Transformation helper v0.0
 *                       PROGRAMMED BY RGBA_CRT 2018-10
 *----------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include <windows.h>
#include <stdio.h>
#include "lz11.h"

//https;//problemkaputt.de/gbatek.htm


int main(void) {
	uint8_t *buf;
	uint8_t *_dst;
	uint32_t _dstSize;
	uint32_t _srcSize;
	
	FILE *in;
	in = fopen("ai_table.csv", "rb");
	if(in==NULL){
		printf("open error\n");
		return 0;
	}


	fseek(in, 0, FILE_END);
	_srcSize = ftell(in);
	fseek(in, 0, FILE_BEGIN);
	
	printf("srcsize: %d\n", _srcSize);

	buf = (uint8_t*)malloc(_srcSize);
	fread(buf, 1, _srcSize, in);
	
	fclose(in);

	// calc dest buffer size
	_dstSize = lz11_getDecompressedSize(buf, _srcSize);
	printf("lz11_getDecompressedSize; %d\n", _dstSize);
	_dst = (uint8_t*)malloc(_dstSize + 1);
	

	LZ11_ERROR ret;
	uint32_t retSize;
	int32_t c;
	uint32_t lt;

	lt = GetTickCount();
	for (c = 0; c < 100; c++) {
		ret = lz11_decompress(buf, _srcSize, _dst, _dstSize, &retSize);
		//printf("decompressed; %d, ret=%d\n", retSize, ret);
	}
	lt = GetTickCount() - lt;
	printf("ProcessTime; %d, ave; %f\n", lt, lt / (float)c);

	//printf((char*)_dst);
	FILE *out;
	out = fopen("out_c.bin", "wb");
	fwrite(_dst, 1, _dstSize, out);
	fclose(out);
}
