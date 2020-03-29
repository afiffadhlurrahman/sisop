#include <iostream>
#include <algorithm> 
using namespace std; 
typedef long long int LL;

LL countLessThan(LL arr[], LL n, LL key) 
{ 
	LL l = 0, r = n - 1; 
	LL index = -1; 
 
	while (l <= r) { 
		int m = (l + r) / 2; 

		if (arr[m] < key) { 
			l = m + 1; 
			index = m; 
		} 
		else { 
			r = m - 1; 
		} 
	} 
	return (index + 1); 
} 

LL countGreaterThan(LL arr[], LL n, LL key) 
{ 
	LL l = 0, r = n - 1; 
	LL index = -1; 

	while (l <= r) { 
		LL m = (l + r) / 2; 

		if (arr[m] <= key) { 
			l = m + 1; 
		} 
		else { 
			r = m - 1; 
			index = m; 
		} 
	} 

	if (index == -1) 
		return 0; 
	return (n - index); 
} 


LL countTriplets(LL n, LL* a, LL* b, LL* c) 
{ 
	sort(a, a + n); 
	sort(b, b + n); 
	sort(c, c + n); 

	LL count = 0; 

	for (LL i = 0; i < n; ++i) { 
		LL current = b[i]; 
		LL a_index = -1, c_index = -1; 

		LL low = countLessThan(a, n, current); 
		LL high = countGreaterThan(c, n, current); 

		count += (low * high); 
	} 

	return count; 
} 

int main() 
{ 
	LL a[100000]; 
	LL b[100000]; 
	LL c[100000]; 
	LL size; 
	
	scanf("%lld",&size);
	for(LL i=0;i<size;i++){
		scanf("%lld",&a[i]);
	}
	
	for(LL i=0;i<size;i++){
		scanf("%lld",&b[i]);
	}
	
	for(LL i=0;i<size;i++){
		scanf("%lld",&c[i]);
	} 
	
	printf("%lld\n",countTriplets(size, a, b, c));
	return 0; 
}
