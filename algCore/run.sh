#!/bin/bash
hms=`date +%H:%M:%S`
out=./output/run_${hms}.log
./build/algCore  > ${out}
cat ${out}
