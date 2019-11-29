#!/bin/bash

for a in $@
do
echo "$a"
echo "аргумент:" $a >> args.txt
done
exit 0
