#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    int testcase, phoneCalls, number, result, kth;
    scanf("%d",&testcase);
    for(int i=0;i<testcase;i++){
        priority_queue<int> numList;
        scanf("%d",&phoneCalls);
        scanf("%d",&kth);        
        for(int j=0;j<phoneCalls;j++){
            scanf("%d",&number);
            if(number == 0){
                if(kth > numList.size()) result = -1;
                else result = numList.top();
                printf("%d\n",result);
            }
            else{
                if(numList.size() < kth) numList.push(number);
                else if(numList.size() == kth && number<numList.top()){
                    numList.pop();
                    numList.push(number);
                }
            }
        }
    }
    return 0;
}