
#include <bits/stdc++.h>
using namespace std;

struct coord {
  double x,y;
};

bool operator<(const coord& a, const coord& b) {
  return a.x < b.x;
}

int main(){
    long long n,m,pointsinrects=0,howfarrightsofar=0,pointpointer=0,rectpointer=0;
    cin>>n>>m;
    long long allrectsX[n],allrectsY[n];
    vector<coord>allpoints;
    for(int i=0;i<n;i++){
        cin>>allrectsX[i]>>allrectsY[i];
    }
    for(int i=0;i<m;i++){
        int allpointsX,allpointsY;
        cin>>allpointsX>>allpointsY;
        allpoints.push_back(coord());
        allpoints[i].x=allpointsX;
        allpoints[i].y=allpointsY;
    }
    sort(allpoints.begin(), allpoints.end());
    while(pointpointer<m and rectpointer<n){
        if(allpoints[pointpointer].x<=allrectsX[rectpointer]+howfarrightsofar and allpoints[pointpointer].x>=howfarrightsofar){
            if(allpoints[pointpointer].x==allrectsX[rectpointer]+howfarrightsofar and allpoints[pointpointer].y>allrectsY[rectpointer] and allrectsY[rectpointer]<allrectsY[rectpointer+1]){
                howfarrightsofar+=allrectsX[rectpointer];
                rectpointer++;
                continue;
            }
                if(allpoints[pointpointer].y<=allrectsY[rectpointer]){
                    pointsinrects++;
                    pointpointer++;
                }else{
                    pointpointer++;
                }
        }else{
            howfarrightsofar+=allrectsX[rectpointer];
            rectpointer++;
        }
    }
    cout << pointsinrects << endl;
    return 0;
}
