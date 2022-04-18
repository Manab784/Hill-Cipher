#!/bin/bash
cat Input.txt | xxd -p | tr -d '\n' | sed -r 's/(.{3})/\1\n/g' | awk 1 ORS=' ' > ./main > Output.txt
