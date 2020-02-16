#!/bin/bash

awk '
BEGIN{FS = ";"}
{
	
	#if($3>="0,45" && $3<="0,55"){
	#	FS = ","
	#	sum+=$1+$2
	#	print "ya"
	#	print $3
	#}
	if($3 ~ '/0,5/'){
		sum_speed+=$1
		sum_angle+=$2
	}
}
END{print "Jumlah Speed: " sum_speed
print "Jumlah Angle: ",sum_angle}
' Container_Crane_Controller_Data_Set_v2.csv
