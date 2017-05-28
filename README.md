# LSPK-Extracter
pk pkh pfs archive extractor for TheLastStory(Wii).

## [Download](https://github.com/RGBA-CRT/LSPK-Extracter/releases)


## usage
	1.Download LSPK-Extractor.zip and unzip to target dir.
	2.D&D .pk files to LSPK-Extractor.exe 
	3.Wait for extraction.


## command line example
	> ls  
	LSPK-Extractor.exe	DSDecmp.exe	boot.pk	boot.pkh	boot.pfs  
	  
	> LSPK-Extractor.exe boot.pk  


## about pk-unpack.exe
	pkファイルとpkhファイルを使いって展開を行います。  
	pfsファイルがない場合に使ってください。  
	拡張子がtxtで出力されていますが、中身はバイナリの場合があります。  
	
	This is unpacker that disuse .pfs file.
	Extracted files extention are .txt, but contents are may be binary data.


## DSDecmp.exeが動作を停止する場合
	/w オプションで実行間隔を調整して実行してください。  
	例：LSPK-Extractor.exe boot.pk /w 100  


## File format infomation
ファイルフォーマットについては以下をご覧ください。  
 + http://forum.xentax.com/viewtopic.php?f=10&t=5938  
 + http://rgbacrt.seesaa.net/article/437742154.html  


ActiveBasic ver4で書かれています。
[RGBALib](https://github.com/RGBA-CRT/RGBALib)を使用しているので、  
コンパイルする場合はこちらも落としてください。
