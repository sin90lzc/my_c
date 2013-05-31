#!/bin/bash

gcc -c share1.c share2.c

gcc -shared -o libshare.so share1.o share2.o

mv libshare.so /home/tim/myspace/lib

echo "extern function1();">share.h
echo "extern function2();">>share.h
echo "extern share1();">>share.h
echo "extern share2();" >> share.h

mv share.h /home/tim/myspace/tmp


gcc main.c -o main.out -L/home/tim/myspace/lib -lshare
