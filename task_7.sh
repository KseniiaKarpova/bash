#!/bin/bash
folder=$1
print() {
for f in $1/*
do

if [[ -d "$f" ]] #проверяет папка это или нет
then
print $f #вызывается рекурсия
else
echo "Размер файла:"
echo -n $(wc -c $f | awk '{print $1}'); # не пустая строка; размер файла в байтах ( вывод лишь размера, без дополнительной инфы)
echo " bytes"
echo "Название файла:"
echo "$f"; 
echo "Права доступа:"
ls -l $f | awk '{print $1}'
echo "------------"
echo
fi
done
}
print $folder
