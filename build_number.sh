#!/bin/bash
number=`cat build_number`
let number++
echo "$number" > build_number #<-- output and save the number back to file
echo "#define BUILD ""$number" | tee include/build_number.h
