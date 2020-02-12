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

func_gen(){
read t
while [ $t -gt 0 ]
do
	bool=true	
	read number
	#echo -e "This is your number : $number"

	func
	
	echo "$bool"
	t=$((t-1))
done
}


afif="ganteng"
echo -e "Hello afif $afif!"
func_gen
echo "See you again"
