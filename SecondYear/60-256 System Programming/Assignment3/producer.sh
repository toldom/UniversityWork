#!/bin/bash

value=$(<storage.txt)

((value+=8))

if [ $value -lt 100 ]
then
	echo "$value" > storage.txt

	echo "from Producer: Current total is $value"

	./a.out consumer.c
else

	echo "from Producer: Now I will take a rest!"

fi
