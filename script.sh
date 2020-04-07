#!/usr/pkg/bin/bash
out=`./matrx`

out2=`readelf -e matrx`

#echo "The second op is $out2"




OUT=${out2%Key to Flags*}
#echo $OUT
OUT2=${OUT#*Headers:}
#echo $OUT2
match=0
result=""
i=0
j=0
declare -a arr=();
k=0
for one_thing in $OUT2; do
       #echo $one_thing
        
        if [ $i -eq 4 -a $j -ge 27 ]; then
		integer=`echo $(( 16#$one_thing ))`
	
		
		result=$result","$integer
        fi	
	if [[ $one_thing =~ .*[0-9]*\] ]]; then
		if [ $match -gt 1 ]; then 
			i=0
		fi
		match=$((match+1))
	else
		i=$((i+1))
	fi
	j=$((j+1))
	
	done
a=$1
b=$2
c=$3
o=`./matrx $a $b $c`
result=$a","$b","$c$result","$o
echo $result
`echo $result >>test.csv`

