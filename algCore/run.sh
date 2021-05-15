#!/bin/bash
hms=`date +%H:%M:%S`
out=./output/run_${hms}.log
cat ./input/paths.txt | ./build/algCore  > ${out}
cat ${out}
