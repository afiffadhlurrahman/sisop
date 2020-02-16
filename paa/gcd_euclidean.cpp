#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 

    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 

        c = getchar(); 
    } 

    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    if (negative) 
        number *= -1; 
} 
  

int main(){
    int a,b;
    //scanf("%d%d",&a,&b);
    fastscan(a);
    fastscan(b);  
    printf("%d\n",gcd(a,b));
    return 0;
}
