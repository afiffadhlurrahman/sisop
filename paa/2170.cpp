/*
    Base case dari problem ini ialah :
        Jika jumlah disk adalah 1, maka pindahkan terlebih dahulu 
        ke rod tengah dan kemudian pindahkan ke rod terakhir.
    Dalam kasus rekursif, maka langkah-langkahnya ialah :
        1. Kita akan memindahkan disk n-1 pertama ke 
           rod terakhir terlebih dahulu.
        2. Kemudian pindahkan disk terbesar ke rod tengah.
        3. Pindahkan disk n-1 pertama dari rod terakhir ke rod pertama.
        4. Pindahkan disk terbesar di rod tengah ke rod terakhir.
        5. Pindahkan semua disk n-1 dari rode pertama ke rod terakhir. 
*/

#include <stdio.h>  

void twistedTOH(int n, char first, char middle, char last) { 
    if (n == 1) { 
  
        printf("%d %c %c\n",n,first,middle); 
        printf("%d %c %c\n",n,middle,last);
  
        return; 
    } 
  
    twistedTOH(n - 1, first, middle, last); 
  
    printf("%d %c %c\n",n,first,middle);
    twistedTOH(n - 1, last, middle, first); 
 	
 	printf("%d %c %c\n",n,middle,last); 
    twistedTOH(n - 1, first, middle, last); 
} 
  
int main() 
{ 
    int n; 
    scanf("%d",&n);
    twistedTOH(n, '1', '2', '3'); 
  
    return 0; 
}
