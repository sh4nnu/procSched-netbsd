#!/usr/pkg/bin/bash
for i in {1..1000}
do
	echo "In $i iter"
	a=$(($RANDOM % 100))
	b=$(($RANDOM % 100))
	c=$(($RANDOM % 100))

	   for j in {1..10}
	   	do
	   `./script.sh $a $b $c`

   	   	done
done
