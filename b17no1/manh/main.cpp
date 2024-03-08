#include <bits/stdc++.h>

using namespace std;

struct point{
    long long x=0;
    long long y=0;
};
vector<point>lines[2];
    void defineline(point start,point end1,int whatline){
        point delta,currsize;
        currsize.x=end1.x-start.x;
        currsize.y=end1.y-start.y;
        if(currsize.x!=0){
            delta.x=currsize.x/abs(currsize.x);
        }
        if(currsize.y!=0){
            delta.y=currsize.y/abs(currsize.y);
        }
        while(!(start.x==end1.x and start.y==end1.y)){
              lines[whatline].push_back(start);
              start.x+=delta.x;
              start.y+=delta.y;
        }
        lines[whatline].push_back(end1);
    }

int main(){
    point start1,end1,start2,end2;
    cin>>start1.x>>start1.y>>end1.x>>end1.y>>start2.x>>start2.y>>end2.x>>end2.y;
    long long shortestdistance=10000;
    defineline(start1,end1,0);
    defineline(start2,end2,1);
    for(int i=0;i<lines[0].size();i++){
        for(int j=0;j<lines[1].size();j++){
            if(abs(lines[0][i].x-lines[1][j].x)+abs(lines[0][i].y-lines[1][j].y)<shortestdistance){
                shortestdistance=abs(lines[0][i].x-lines[1][j].x)+abs(lines[0][i].y-lines[1][j].y);
            }
        }
    }

    cout << shortestdistance << endl;
    return 0;
}
/*
3 2 6 2
1 6 1 3

4 2 4 4
6 6 2 6
*/
