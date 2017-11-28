#!/bin/bash

clear

files=(`ls`)
numOfFiles=`ls | wc -w`

echo practice: shell command and array
 
echo List all directories and files in current directory: ${files[*]}

echo The number of files and directories is: $numOfFiles

echo First element in the list is: ${files[0]}

echo All elements in this list:
for ((counter=0;counter<numOfFiles;counter+=1))
do
	echo ${files[counter]}

done
