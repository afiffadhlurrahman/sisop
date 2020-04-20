#include<cstdio>
#include<algorithm>
typedef long long LL;

void pre_process(LL a[]){
	for(int i=2;i<=30;i++){
		a[i-1] = ((LL)i*(LL)(2<<(i-1)))-1ll;
		//printf("%lld\n",a[i-1]);
	}
//	LL b = (2*(2<<1))-1;
//	printf("%lld",b);
	
}

int main(){
	LL a[33], n;
	int t;
	pre_process(a);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		//printf("%lld\n",n);
		for(int j=1;j<=30;j++){
			if(n<=a[j]){
				printf("%d\n",j);
				j=31;
			}
		}
	}
	return 0;
}
