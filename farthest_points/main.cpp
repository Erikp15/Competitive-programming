#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e6+1;
ll n;

class point{
public:
    ll x,y;
    point(){
        x=1e9; y=1e9;
    }
    point(ll a,ll b){
        x=a; y=b;
    }
};

point lowest;
point points[Size];

ll oriented_area(point a,point b,point c){
    ll area=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(area>0) return 1;
    if(area<0) return -1;
    return 0;
}
bool comp(point a,point b){
    ll area=oriented_area(lowest,a,b);
    return area<0;
}

void sorting(){
    for(ll i=n-1;i>=0;i--){
        for(ll j=i;j>=0;j--){
            if(comp(points[i],points[j])){
                swap(points[i],points[j]);
            }
        }
    }
}

ld dist(point a,point b){
    return sqrt((a.x+b.x)*(a.x+b.x)+(a.y+b.y)*(a.y+b.y));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
        if(lowest.y>points[i].y){
            lowest=points[i];
        }
    }
    sort(points,points+n,comp);
    reverse(points,points+n);
    vector<point> hull;
    hull.push_back(lowest);
    for(ll i=0;i<n;i++){
        if(points[i].x!=lowest.x and points[i].y!=lowest.y){
            while(hull.size()>1 and oriented_area(hull[hull.size()-2],hull[hull.size()-1],points[i])<0){
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
    }
    cout<<endl;
    for(auto itr:hull){
        cout<<itr.x<<" "<<itr.y<<endl;
    }
    hull.push_back(lowest);
    ll line1=1,line2=2;
    ld ans=0;
    for(;line2<hull.size();line2++){
        ans=max(ans,dist(hull[line1-1],hull[line2-1]));
        if(0>oriented_area(hull[line1-1],hull[line1],*new point(hull[line2].x-hull[line2-1].x+hull[line1].x,hull[line2].y-hull[line2-1].y+hull[line1].y))){
            if(line1!=line2-1){
                line1++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
4 5
1 1
0 0
3 2

6
1 1
0 0
3 2
4 5
10 3
-1 2
*/
