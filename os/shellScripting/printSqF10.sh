#!/bin/bash

# to print the first 10 perfect squres using shell scripting

for i in {1..10}
do
	let sq=$(($i*$i))
	echo "$sq"
done
