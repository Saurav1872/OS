#!/bin/bash

n=10
i=1
a=0
b=1
while [ $i -lt $n ]
do
	echo -n "$a "
	temp=$b
	b=`expr $a + $b`
	a=$temp
	i=`expr $i + 1`
done