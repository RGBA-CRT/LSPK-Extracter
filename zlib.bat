REM �W�J���ďo�Ă����t�@�C����zlib���k�t�@�C���̏ꍇ������
REM openssl �̃C���X�g�[�����K�v
move %1 %1_cmp
call openssl zlib -d -in %1_cmp -out %1
del %1_cmp
