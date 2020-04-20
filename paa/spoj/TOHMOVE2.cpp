#include<iostream>

int main(){
	long long int disk,move,num,count,fi,T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&disk,&move);
	
		num = move ^ (move-1);
		count=0; 
	    while (num){ 
	    	count += num & 1; 
	    	num >>= 1; 
	    }
		
		
		if(disk%2==0){
			if(count%2==0){
				if(move%3==2){
					printf("%lld : A => C\n",count);	
				}
				else if(move%3==0){
					printf("%lld : C => B\n",count);
				}
				else if(move%3==1){
					printf("%lld : B => A\n",count);
				}
			}
			else if(count%2==1){
				if(move%3==1){
					printf("%lld : A => B\n",count);	
				}
				else if(move%3==0){
					printf("%lld : B => C\n",count);
				}
				else if(move%3==2){
					printf("%lld : C => A\n",count);
				}
			}	
		}
		else if(disk%2==1){
			if(count%2==1){
				if(move%3==1){
					printf("%lld : A => C\n",count);	
				}
				else if(move%3==0){
					printf("%lld : C => B\n",count);
				}
				else if(move%3==2){
					printf("%lld : B => A\n",count);
				}
			}
			else if(count%2==0){
				if(move%3==2){
					printf("%lld : A => B\n",count);	
				}
				else if(move%3==0){
					printf("%lld : B => C\n",count);
				}
				else if(move%3==1){
					printf("%lld : C => A\n",count);
				}
			}	
		}
	}
	return 0;
}
