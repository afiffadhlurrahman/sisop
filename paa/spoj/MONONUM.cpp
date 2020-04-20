#include<iostream>

int main(){
	int T,n;
	double del_fac = 40320,sum;
	double rasio1,rasio;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum=n+1;
		for(int i=n+2;i<n+9;i++){
			sum*=i;
		}
		rasio = ((double)(n+9)/9)-((double)(del_fac/sum));
		printf("%.6f\n",rasio);
	}
	return 0;
}
