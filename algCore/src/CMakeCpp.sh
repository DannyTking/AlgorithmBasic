#!/bin/bash

echo "create class $1.cpp $1.h"

inc=$1.h
touch $inc

echo "#pragma once" > $inc
echo '#include "inc_std.h"' >> $inc
echo "// date:`date +"%Y-%m-%d %H:%M:%S"` " >> $inc
echo "class $1 {};" >> $inc

cpp=$1.cpp

echo "#include \"$inc\" " > $cpp


echo "create class $1.cpp $1.h success."
