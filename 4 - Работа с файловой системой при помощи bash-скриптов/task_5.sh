#!/bin/bash

nameFile=$1
fileType=$2
folder=$3

for f in $folder/*
do
filename=$(basename "$f")
extension=${filename##*.}

if [ $extension == $fileType ]
then
echo $filename >> $nameFile
fi

echo "$f"

done

