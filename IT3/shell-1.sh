#!/usr/bin/env bash

declare -i C F
read -p "ENTER VALUE IN DEG celius: " C
F=$(( 18 * C + 320 ))
echo "TEMPERATURE IN FAHRENHEIT IS ${F:0:-1}.${F: -1: 1}"
