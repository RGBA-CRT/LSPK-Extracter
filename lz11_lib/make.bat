gcc lz11.c -O2 -o lz11.dll -shared  -Wl,-s
upx  lz11.dll 
gcc main.c lz11.dll -Wl,-s -o lz11_test.exe
copy lz11.dll ..\