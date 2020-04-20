#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct point{
    int x;
    int y;
};

double coor(point p1, point p2){
    long long cx = p2.x - p1.x;
    long long cy = p2.y - p1.y;
    return sqrt(cx*cx + cy*cy);
}

double min(point* p, int n){
    double ans = 1000000001.0, ends[n][n-1];
    for(int j=0;j<n-1;++j){
        double m = 1000000002.0;
        for(int x=0; x<j;++x)
            m = min(m, ends[j][x]+dist(p[x],p[j+1]));
        
		if(m>=1000000000.0) 
			m=dist(p[0],p[1]);
        
		ends[j+1][j] = m;
        for(int i=j+2;i<n;++i)
            ends[i][j] = ends[i-1][j] + dist(p[i],p[i-1]);
    }

    for(int j=0;j<n-1;++j)
        ans = min(ans, ends[n-1][j] + dist(p[j],p[n-1]));

    return ans;
}

int main(){
    int n,x;
    cin>>n;
    point p[n];
    for(int i=0;i<n;++i)    
		cin>>p[i].x>>p[i].y;
    if(n<=1)
        cout<<"0.00"<<endl;
    else 
		cout<<std::fixed<<setprecision(2)<<mindist(p,n)<<endl;
}
