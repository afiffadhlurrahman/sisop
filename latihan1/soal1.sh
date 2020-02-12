#!/bin/bash

func(){
	if [ $number -le 1 ]
	then
		bool=false
	fi

	for ((i=2; i<number; i=i+1))
	do
		if [ $(($number % $i)) -eq 0 ]
		then
			bool=false
		fi
	done
}

afif=$ganteng
echo -e "Hello afif $afif!"
t=$#
myArray=( "$@" )

for arg in "${myArray[@]}"; do
	bool=true
	number=$arg
	echo "$number"
	func
	echo "$bool"
done

echo "See you again"
