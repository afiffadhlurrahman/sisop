#include <iostream>
#include <algorithm>
#include <vector>
#define maxNum (LL)(1e18) 
 
using namespace std; 
typedef long long int LL;

vector<LL> v; 
  
void precompute() 
{ 
    LL x = 1, y = 1; 

    while (x <= maxNum) { 
  
        while (x * y <= maxNum) { 
            v.push_back(x * y); 
            y *= 3; 
        } 
  
        x *= 2; 

        y = 1; 
    } 
  
    sort(v.begin(), v.end()); 
} 
  
void countNum(LL l, LL r) 
{ 
    printf("%lld\n",upper_bound(v.begin(), v.end(), r) - upper_bound(v.begin(), v.end(), l - 1));
} 

int main() 
{ 
    LL l, r; 
    precompute(); 
    while(scanf("%lld %lld",&l,&r) != EOF){
	countNum(l, r); 
    }
    
    return 0; 
}
