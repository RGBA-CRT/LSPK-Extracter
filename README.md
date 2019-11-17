# LSPK-Extractor
pk pkh pfs archive extractor for TheLastStory(Wii) and other.

## [Download](https://github.com/RGBA-CRT/LSPK-Extracter/releases)


## usage
1. Download LSPK-Extractor.zip and unzip to target dir.
1. D&D .pk files to LSPK-Extractor.exe 


## command line example
```bash
> ls  
LSPK-Extractor.exe	DSDecmp.exe	boot.pk	boot.pkh	boot.pfs  

> ./LSPK-Extractor.exe
Usage : LSPK-Extractor [/v][/l][/e][/dec exename] pkfile
        /v - Verbose mode.
        /l - Listup files.
        /e - Extract only (do not decompless) mode.
        /dec exename - Use commandline decompresser. (deprecated)
        /zlib - force zlib decompress mode
        /lz11 - force lz11 decompress mode

> ./LSPK-Extractor.exe boot.pk /v
The Last Story .pk .pkh .pfs Extractor v3.0         Programmed by RGBA_CRT 2016-2019

Verbose mode.
Load:boot.pfs

PkhInfo:
 Count of files : 217
 Actual table size : 3472 bytes
 Block Size : 16 bytes

PkInfo:
 File Size : 1.8 MB
 Compress Type : LZ10/LZ11 Compress

Decompress Type: LZ10/LZ11 Compress
Decompress Method: Using decompressor DLL

Extracting.
[    26 hs:1D9635ED ad:00 00000000 si:   4K] boot/ai_table.csv
  :
  :
[   193 hs:EAB61415 ad:00 001C58C0 si:  50K] hbm/HomeButton2/SpeakerSe.arc

total dir 14, file 217, process time 1482ms

```

## compress type
+ zlib, lz11圧縮に対応しています。
    + The Last Story is lz11 compression.
    + Fate/EXTELLA is zlib compression.
    + Soul Sacrifice Delta is zlib compression.
+ v3.0以降では圧縮タイプを自動判定します。また、zlib1.dll, lz11.dllによって解凍されます。
+ This extractor supports zlib or lz11 compress type.
    + The Last Story is lz11 compression.
    + Fate/EXTELLA is deflate(zlib) compression.
    + Soul Sacrifice Delta is deflate(zlib) compression.
+ In v3.0 or later, the compression type is automatically judged.
+ It is also extracted by zlib1.dll, lz11.dll.

## File format infomation  
 + http://forum.xentax.com/viewtopic.php?f=10&t=5938  
 + http://rgbacrt.seesaa.net/article/437742154.html  

## build
 + [ActiveBasic ver4](https://www.activebasic.com/)で書かれています。
 + [RGBALib](https://github.com/RGBA-CRT/RGBALib)を使用しているので、コンパイルする場合はこちらも落としてください。
 + This program is compiled by [ActiveBasic ver4](https://www.activebasic.com/)
 + And using [this](https://github.com/RGBA-CRT/RGBALib) lib.
