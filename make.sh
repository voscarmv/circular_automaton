#!/bin/bash

gcc -c libcellauto.c -lm
ar rs libcellauto.a libcellauto.o
gcc -L. -I. -o b5 b5.c -lm -lcellauto
