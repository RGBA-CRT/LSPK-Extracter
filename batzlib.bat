@echo off
for %%i in (*.*) do (
call openssl zlib -d -in %%i -out %%i_ext.dds
)
pause