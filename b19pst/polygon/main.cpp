#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class point{
public:
    ll x,y;
    bool operator <(const point& a){
        if(x==a.x){
            return y<a.y;
        }
        return x<a.x;
    }
};

bool is_clockwise(point p1,point p2,point p3){
    return (p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x)<=0;
}
bool is_counterclockwise(point p1,point p2,point p3){
    return (p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x)>=0;
}
    vector<point> points,convex_hull_top,convex_hull_bot;
    double total_area=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x,y;
    for(ll i=0;cin>>x>>y;i++){
        point tmp; tmp.x=x; tmp.y=y;
        points.push_back(tmp);
    }
    sort(points.begin(),points.end());
    point small=points[0],large=points[points.size()-1];
    convex_hull_top.push_back(points[0]);
    convex_hull_bot.push_back(points[0]);
    for(ll i=1;i<points.size();i++){
        if(is_clockwise(points[0],points[i],points[points.size()-1])){
            ll con_size=convex_hull_top.size()-1;
            if(convex_hull_top.size()>1){
                while(con_size>0 and is_counterclockwise(convex_hull_top[con_size-1],convex_hull_top[con_size],points[i])){
                    convex_hull_top.pop_back();
                    con_size=convex_hull_top.size()-1;
                }
            }
            if(points[i].y<small.y)small.y=points[i].y;
            if(points[i].y>large.y)large.y=points[i].y;
            convex_hull_top.push_back(points[i]);
        }
        if(is_counterclockwise(points[0],points[i],points[points.size()-1])){
            ll con_size=convex_hull_bot.size()-1;
            if(convex_hull_bot.size()>1){
                while(con_size>0 and is_clockwise(convex_hull_bot[con_size-1],convex_hull_bot[con_size],points[i])){
                    convex_hull_bot.pop_back();
                    con_size=convex_hull_bot.size()-1;
                }
            }
            if(points[i].y<small.y)small.y=points[i].y;
            if(points[i].y>large.y)large.y=points[i].y;
            convex_hull_bot.push_back(points[i]);
        }
    }
    if(convex_hull_bot.size()>1){
        for(ll i=0;i<convex_hull_bot.size()-1;i++){
            total_area-=abs(convex_hull_bot[i].y+convex_hull_bot[i+1].y)*abs(convex_hull_bot[i].x-convex_hull_bot[i+1].x)/2.0;
        }
    }
    if(convex_hull_top.size()>1){
        for(ll i=convex_hull_top.size()-1;i>0;i--){
            total_area+=abs(convex_hull_top[i].y+convex_hull_top[i-1].y)*abs(convex_hull_top[i].x-convex_hull_top[i-1].x)/2.0;
        }
    }
    if(double(total_area-ll(total_area))>0){
        cout<<setprecision(0)<<fixed<<floor(total_area)<<".5"<<endl;
    }else{
        cout<<setprecision(0)<<fixed<<total_area<<endl;
    }
    return 0;
}
/*
8
1 1
4 5
4 2
2 2
5 4
3 6
1 3
4 4
11.5

6
1 1
5 5
4 2
4 3
2 5
3 4
works

2 38
20 46
64 53
31 27
13 11
93 19
85 37

0 10
5 16
10 20
15 16
20 10
15 4
10 0
5 4
*/
