#!/bin/bash

# to print the first 10 perfect squres using shell scripting
i=1
num=10
while [ $i -lt $num ]
do
	let sq=$(($i*$i))
	echo "$sq"
    i=`expr $i + 1`
done
