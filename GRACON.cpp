#include<iostream>
using namespace std;
int parent[10001];

int find(int u){
    if(parent[u]==u) return u;
    else return parent[u] = find(parent[u]);
}

int main(){
    int t,n,m,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++) parent[i]=i;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            int u = find(a);
            int v = find(b);
            if(u != v){
                if(u>v) parent[u]=v;
                else parent[v]=u;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==find(i)){
                ans++;
            }
        }
        if(ans==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}