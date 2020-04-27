#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
int getNum(){
    int res = 0;
    char c;
    int b = 0;
    while (true)
    {
        c = getchar_unlocked();
        if(c == '-') b = 1;
        if(c==' '|| c=='\n') continue;
        else break;
    }
    if(c != '-') res = c-'0';
    while(true){
        c = getchar_unlocked();
        if(c >= '0' && c <='9') res = 10 * res + c - '0';
        else break;
    }
    if(b==1) res*=-1;
    return res;
}
 
int main(){
    int testcase, phoneCalls, number, result, kth;
    testcase = getNum();
    for(int i=0;i<testcase;i++){
        priority_queue<int> numList;
        phoneCalls = getNum();
        kth = getNum();
        for(int j=0;j<phoneCalls;j++){
            number=getNum();
            if(number == 0){
                if(kth > numList.size())    result = -1;
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
