typedef enum _LZ11_ERROR {
	LZ_OK = 0,
	LZ_UNKNOWN_FORMAT,
	LZ_BUFFER_ERROR,
	LZ_DATA_ERROR
} LZ11_ERROR;

LZ11_ERROR __stdcall lz11_decompress(uint8_t *src, uint32_t srcLen, uint8_t *dst, uint32_t dstLen, /* ByRef */ uint32_t *decompressedLen);
uint32_t __stdcall lz11_getDecompressedSize(uint8_t *src, int32_t srcLen);
