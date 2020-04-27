#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    set<int> SET;
    pair<set<int>::iterator,bool> stat;
    vector<int> VI;
    for(int i=0;i<n;i++){
        int inp;
        scanf("%d",&inp);
        stat = SET.insert(inp);
        if(stat.second) VI.push_back(inp);
    }
    n = VI.size();
    for(int i=0;i<n;i++){
        printf("%d ",VI[i]);
    }
    printf("\n");
    reverse(VI.begin(),VI.end());

    for(int i=0;i<n;i++){
        printf("%d ",VI[i]);
    }
    printf("\n");
    return 0;
}
