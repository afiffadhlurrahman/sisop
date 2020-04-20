#include <iostream>
#define M 1000000007
using namespace std;
 
int m,n;
 
int hasil(){
	int dp[n+1][m+1];

	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++) 
			dp[i][j] = 0;
	}

	for (int i=0;i<=m;i++) 
		dp[n-1][i] = 1;
 
	long long flag = n,flag1 = m;
	long long int temp = flag1-(flag*(flag+1))/2;

	if (temp<0) 
		return 0;
 
	for (int i=n-2;i>=0;i--){
		for (int j=temp;j>=temp-(n-i)+1;j--){
			int k = 0;
			while(j-(n-i)*k>=0){
				dp[i][j] = (dp[i][j]+dp[i+1][j-(n-i)*k])%M;		
				k++;
			}
		}
		for (int j=temp-(n-i);j>=0;j--){
			dp[i][j] = (dp[i][j+n-i]-dp[i+1][j+n-i])%M;
			if (dp[i][j]<0) dp[i][j]+=M;
		}
	}
	return dp[0][temp];
}
 
int main(){
	int T,count=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		printf("Case %d: %d\n",count++,hasil());
	}
	return 0;
}
