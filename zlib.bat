REM 展開して出てきたファイルがzlib圧縮ファイルの場合がある
REM openssl のインストールが必要
move %1 %1_cmp
call openssl zlib -d -in %1_cmp -out %1
del %1_cmp
