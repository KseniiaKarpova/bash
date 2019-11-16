#!/bin/bash

file=$1
compileFile=$2
if [[ (-f $1) && (-f $2) ]]
then
gcc $1 -o $2;
./$2
else 
echo "file not found"
exit 1
fi

