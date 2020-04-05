out=`./matrx`

out2=`readelf -e matrx`

#echo "The second op is $out2"




OUT=${out2%Key to Flags*}
#echo $OUT
OUT2=${OUT#*Headers:}
#echo $OUT2
match=0
i=0
j=0
declare -a arr=();
k=0
for one_thing in $OUT2; do
       # echo $one_thing
	if [[ $one_thing =~ .*[0-9]*\] ]]; then
		if [ $match -gt 1 ]; then 

			#echo "index i  $i index j $j"
			i=0
			`echo ${arr[*]} >> test.csv`

			arr=()

		else
			arr=()
		fi
		match=$((match+1))
	else
		if [ $i -ne 0 ]; then
			arr[$i]=','
		fi
		arr[$i]=${arr[$i]}$one_thing
		i=$((i+1))
	fi
	j=$((j+1))
	
	done
