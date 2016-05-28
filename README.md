# LSPK-Extracter
pk pkh pfs archive extractor for TheLastStory.

## 使い方：
	1.LSPK-Extractor.zipをダウンロード、展開
	2.pkファイルをLSPK-Extractor.exeにドラッグ
	3.展開されます


##コマンドラインで使う場合の例：
	> ls  
	LSPK-Extractor.exe	DSDecmp.exe	boot.pk	boot.pkh	boot.pfs  
	  
	> LSPK-Extractor.exe boot.pk  


##pk-unpack.exeについて
	pkファイルとpkhファイルを使いって展開を行います。  
	pfsファイルがない場合に使ってください。  
	拡張子がtxtで出力されていますが、中身はバイナリの場合があります。  


##DSDecmp.exeが動作を停止する場合
	/w オプションで実行間隔を調整して実行してください。  
	例：LSPK-Extractor.exe boot.pk /w 100  


ファイルフォーマットについては以下をご覧ください。  
	http://forum.xentax.com/viewtopic.php?f=10&t=5938  
	http://rgbacrt.seesaa.net/article/437742154.html  


ActiveBasic ver4で書かれています。
RGBALib[<https://github.com/RGBA-CRT/RGBALib>]を使用しているので、  
コンパイルする場合はこちらも落としてください。
