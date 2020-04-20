/*
	tidak orang yang mendapatkan kartu ace yang duduk bersebelahan.    
    misalkan :
	n = 1, maka jumlah cara untuk menangani kartu adalah 2
	n = 2, maka jumlah cara untuk menangani kartu adalah 3 {kosong, orang1, orang2}
	n = 3, maka jumlah cara untuk menangani kartu adalah 4 {kosong, orang1, orang2, orang3}
	n = 4, maka jumlah cara untuk menangani kartu adalah 7 {kosong, orang1, orang2, orang3, orang4, orang1 dan orang2, orang2 dan orang3 }
	.
	.
	dst
*/

#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int f[T+2];
	f[0] = 2; 
	f[1] = 3;
	f[2] = 4; 
	
	if(T>2){
		for (int i = 3; i <= T; i++) { 
			f[i] = f[i-1] + f[i-2]; 
		} 
	}
	printf("%d\n",f[T-1]);
        return 0;
}
