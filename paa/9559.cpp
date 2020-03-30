/* Analisis singkat :
	Untuk menyelesaikan problem ini kita perlu untuk setiap row 
	dan kolom sama hasil xor nya.
	
	Kita akan menggunakan 4 kali looping
	Untuk looping pertama dan kedua jika n yang diminta lebih dari 4.
	Untuk looping yang ketiga dan keempat adalah untuk memasukkan number 
	yang memenuhi kondisi xor (dalam baris dan kolom).

	Jadi kita dapat membagi matriks n x n menjadi matriks 4 x 4 yang 
	lebih kecil dengan baris dan kolom n/4 dan mengisi bagian dalam 
	dengan cara itu xor dari setiap baris dan kolom adalah 0.

	Hasil dari xor harus 0 agar memenuhi syarat yang diberikan sehingga
	Divide nxn matriks tersebut menjadi n/4 setiap matriks untuk masing
	masing baris n/4, dimana setiap matriks berukuran 4x4.
*/

#include <iostream> 
using namespace std;  

int main() 
{ 
	int n; 
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	
	cin >> n;
	 
	cout.tie(NULL);
    

	int x = 0; 
	for (int i = 0; i < n / 4; i++) { 
		for (int j = 0; j < n / 4; j++) { 
			for (int k = 0; k < 4; k++) { 
				for (int l = 0; l < 4; l++) { 
					arr[i * 4 + k][j * 4 + l] = x; 
					x++; 
				} 
			} 
		} 
	} 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) { 
			cout << arr[i][j]; 
			if(j!=n-1){
				cout << " ";
			}
		} 
		cout << "\n";
	} 
	return 0; 
} 

