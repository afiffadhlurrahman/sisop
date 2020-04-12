#include <cstdio>
#include <algorithm>
using namespace std;

int dp[2][2];
int n, e1, e2, x1, x2;
int a[2][1024], t[2][1024];

int GetInt(){
	int r = 0;
	char c;
	while(true){
		c = getchar_unlocked();
		if(c==' ' || c=='\n')	
			continue;
		else	
			break;
	}
	r = c-'0';
	while(true){
		c = getchar_unlocked();
		if(c>='0' && c<='9')
			r = 10 * r + c - '0';
		else
			break;	
	}
	return r;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		dp[0][0]=GetInt();
		dp[1][0]=GetInt();
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				a[i][j]=GetInt();
			}
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<n-1;j++){
				t[i][j]=GetInt();
			}
		}
		x1 = GetInt();
		x2 = GetInt();
		dp[0][0] += a[0][0];
		dp[1][0] += a[1][0];
		for(int i=1;i<n;i++){
			dp[0][i%2] = min(dp[0][(i-1)%2], dp[1][(i-1)%2]+t[1][i-1])+a[0][i];
			dp[1][i%2] = min(dp[1][(i-1)%2], dp[0][(i-1)%2]+t[0][i-1])+a[1][i];
		}
		printf("%d\n",min(dp[0][(n-1)%2]+x1,dp[1][(n-1)%2]+x2));	
	}
	return 0;
}
