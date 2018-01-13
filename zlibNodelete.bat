REM 展開して出てきたファイルがzlib圧縮ファイルの場合がある
REM openssl のインストールが必要
call openssl zlib -d -in %1 -out %1_ext.bin

