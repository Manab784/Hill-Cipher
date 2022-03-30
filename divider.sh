#!/bin/bash
read string
echo $string | sed -r 's/(.{3})/\1\n/g' | awk 1 ORS=' '
