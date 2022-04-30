#!/bin/bash
val=`cat Input.txt | tr -d '\n' | sed -r 's/(.{3})/\1\n/g' | awk 1 ORS=' ' `
touch Output.txt
> Output.txt
for value in $val 
do
  echo `echo "$value"|./main` >>Output.txt
done