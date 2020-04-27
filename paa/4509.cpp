#include<bitset>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char comm[15];
bitset<1000004> SET[25];

int main(){
    int n,q,x,y,t,a;
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        for (int j=1; j<=t; j++){
            scanf("%d",&a);
            SET[i][a]=true;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%s",comm);
        scanf("%d",&x);
        scanf("%d",&y);
        bitset<1000004> res;
        if(strcmp("INTERSECTION",comm)==0){
            res=SET[x]&SET[y];
            printf("%d\n",res.count());
        }
        else{
            res = SET[x]|SET[y];
            printf("%d\n",res.count());
        }
    }
    return 0;
}
