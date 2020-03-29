#include <iostream> 
using namespace std; 
typedef long long int LL;

bool check(LL mid, LL array[], LL n, LL k) 
{ 
	LL count = 0; 
	LL sum = 0; 
	for (LL i = 0; i < n; i++) { 

		if (array[i] > mid) 
			return false; 

		sum += array[i]; 

		if (sum > mid) { 
			count++; 
			sum = array[i]; 
		} 
	} 
	count++; 

	if (count <= k) 
		return true; 
	return false; 
} 


long long int solve(LL array[], LL n, LL k) 
{ 
	LL start = 1; 
	LL end = 0; 

	for (LL i = 0; i < n; i++) { 
		end += array[i]; 
	} 
 
	LL answer = 0; 
	while (start <= end) { 
		LL mid = (start + end) / 2; 

		if (check(mid, array, n, k)) { 
			answer = mid; 
			end = mid - 1; 
		} 
		else { 
			start = mid + 1; 
		} 
	} 
	return answer; 
} 

int main() 
{ 
	
	LL n; 
	LL k; 
	scanf("%lld %lld",&n,&k);
	LL array[n+1];
	for(LL i=0;i<n;i++){
		scanf("%lld",&array[i]);
	}
	printf("%lld\n",solve(array, n, k));
}
