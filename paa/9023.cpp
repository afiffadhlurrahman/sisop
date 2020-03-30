/* Analisis singkat :
	Buat array yang akan digunakan (array yang dicari) 
	dengan elemen terakhir yang diperbaiki yang akan 
	increase jika solusinya tidak valid atau decrease 
	jika valid seperti dalam binary search.
	
	Cek bahwa semua elemen array yang dicari lebih besar 
	atau sama dengan array input untuk melakukan operasi 
	pada elemen agar sama dengan elemen yang diinginkan. 
	Kemudian hitung operasinya. Cari nilai minimum yang
	mungkin dari elemen terakhir yang memenuhi kondisi 
	semua elemen dalam array yang dicari.
*/

#include <iostream>
#include <algorithm> 
using namespace std; 
typedef long long int LL;

bool check(LL m, LL n, LL arr[]) 
{ 
	LL final[n]; 
	for (LL i = n - 1; i >= 0; i--) { 
		final[i] = m; 
		m--; 
	} 

	for (LL i = 0; i < n; i++) { 
		if (arr[i] > final[i] || final[i] < 1) { 
			return false; 
		} 
	} 
	
	return true; 
} 


LL hasil(LL arr[], LL n) 
{ 
	LL start = (LL)arr[n - 1]; 
	LL end = *(max_element(arr, arr + n)) + n; 
	LL max_arr = 0; 

	while (start <= end) { 
		LL mid = (start + end) / 2; 

		if (check(mid, n, arr)) { 

			max_arr = mid; 
			end = mid - 1; 
		} 
		else { 
			start = mid + 1; 
		} 
	} 

	LL final[n]; 
	for (LL i = n - 1; i >= 0; i--) { 
		final[i] = max_arr; 
		max_arr--; 
	} 

	LL operations = 0; 
	for (LL i = 0; i < n; i++) { 
		operations += (final[i] - arr[i]); 
	} 

	return operations; 
} 

int main() 
{ 
	LL arr[1000000]; 
	LL n; 
	scanf("%lld",&n);
	for(LL i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	printf("%lld\n",hasil(arr, n));

	return 0; 
} 


