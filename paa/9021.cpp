#include <bits/stdc++.h> 
using namespace std; 
typedef long long int LL;
#define maxNum (int)(1e8) 
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
    cout << upper_bound(v.begin(), v.end(), r) - upper_bound(v.begin(), v.end(), l - 1) << endl; 
} 

int main() 
{ 
    LL l, r; 
  	
  	while(scanf("%lld %lld",&l,&r) != EOF){
  		memset(&v[0], 0, sizeof(v[0]) * v.size());
  		precompute(); 
		countNum(l, r); 
		//printf("%lld %lld\n",l,r); 
	}
    
    return 0; 
}
