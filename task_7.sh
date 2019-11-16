#!/bin/bash
folder=$1
print() {
for f in $1/*
do

if [[ -d "$f" ]]
then
print $f
else
echo "Размер файла:";
echo -n $(wc -c $f | awk '{print $1}');
echo " bytes";
echo "Название файла:";
wc -c $f | awk '{print $2}'; 
echo "Права доступа:";
ls -l $f | awk '{print $1}';
echo "------------";
echo
fi
done
}
print $folder

