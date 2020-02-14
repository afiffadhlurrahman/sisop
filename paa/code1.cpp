#include<bits/stdc++.h>
using namespace std;

int main(){
    int pen;
    int apple;

    scanf("%d %d",&pen,&apple);

    int lol = 100500;
    int trash = 0;

    while(pen!=apple){
        if(pen>apple)
            pen = pen-apple;
        int pineapple = pen;
        pen = apple;
        apple = pineapple;
    }

    printf("%d\n",pen);
    return 0 ;
}
