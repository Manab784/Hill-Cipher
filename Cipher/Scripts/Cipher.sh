#!/bin/bash
val=`cat Input.txt | xxd -p | tr -d '\n' | sed -r 's/(.{3})/\1\n/g' | awk 1 ORS=' ' `
touch Output.txt
echo "" > Output.txt
for value in $val 
do
  echo $value | ./main >>Output.txt
done

#Provided main has to be in the same folder
