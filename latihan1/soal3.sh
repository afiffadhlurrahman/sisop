#!/bin/bash

awk '
BEGIN{FS = ","}
{
	if($4==5){
		sum+=$1+$2
	}
}
END{print "Jumlah: " sum}
' Container_Crane_Controller_Data_Set.csv
