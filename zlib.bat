#展開して出てきたファイルがzlib圧縮ファイルの場合がある
openssl zlib -d -in %1 -out %1_d.bin