#!/bin/bash
read string
echo $string | xxd -p | tr -d '\n' | sed -r 's/(.{3})/\1\n/g' | awk 1 ORS=' '
