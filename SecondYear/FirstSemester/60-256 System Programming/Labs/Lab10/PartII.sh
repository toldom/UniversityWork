#!/bin/bash

clear

file1Col1Str=`cat 60-212 | awk '{print $1}'`
file1Col2Str=`cat 60-212 | awk '{print $2}'`
file2Col1Str=`cat 60-256 | awk '{print $1}'`
file2Col2Str=`cat 60-256 | awk '{print $2}'`

file1Col1=(${file1Col1Str// / })
file1Col2=(${file1Col2Str// / })
file2Col1=(${file2Col1Str// / })
file2Col2=(${file2Col2Str// / })

file1Size=${#file1Col1[@]}
file2Size=${#file2Col1[@]}

if (($file1Size>=$file2Size)); then
	largestSize=file1Size
else
	largestSize=file2Size
fi

passes212=()
passes256=()

for ((i=0;i<$largestSize;i+=1)); do
	if ((file1Col2[$i]>=50));then
		passes212[$i]=${file1Col1[$i]}
	else
		passes212[$i]=-1
	fi
done

for ((i=0;i<$largestSize;i+=1)); do
	if ((file2Col2[$i]>=50));then
		passes256[$i]=${file2Col1[$i]}
	else
		passes256[$i]=-1
	fi
done

passesBoth=()

for((i=0;i<$largestSize;i+=1));do
	if((${passes212[$i]}==${passes256[$i]}));then
		passesBoth[$i]=${passes212[$i]}
	fi
done

sizeOfBoth=${#passesBoth[@]}

echo ${passesBoth[@]}
