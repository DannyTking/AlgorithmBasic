#!/bin/bash
hms=`date +%H:%M:%S`
out=out_${hms}.log
cat ./input/paths.txt | ./a.out  > ${out}
cat ${out}
