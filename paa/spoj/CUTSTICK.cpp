#include<iostream>
using namespace std;
#define MAX 100001

void preprocess(int dp[MAX]){
	for(int i=2; i<MAX; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
}

int main(){
	int n, count, dp[MAX] = {1,1};
	preprocess(dp);
	while(scanf("%d", &n) != EOF){
		count = 0;
		while(n >= dp[count]){
			n -= dp[count++];
		}
		printf("%d\n",count);
	}
	return 0;
}
