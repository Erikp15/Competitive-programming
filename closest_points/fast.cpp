#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Point{
    ld x,y;
    Point(){
        x=0;
        y=0;
    }
    Point(ld a,ld b){
        x=a;
        y=b;
    }
};

bool comp(const Point& a,const Point& b){
    return a.x<b.x;
}

bool comp2(const Point& a,const Point& b){
    return a.y<b.y;
}

const ll Size=1e6+1;
Point a[Size];

ld dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

pair<ld,vector<Point>> solve(ll l,ll r){
    vector<Point> ysorted;
    if(l==r){
        ysorted.push_back(a[l]);
        ysorted.push_back(*new Point(1e18,1e18));
        return {1e18,ysorted};
    }else{
        ll mid=(l+r)/2;
        pair<ld,vector<Point>> left_ans=solve(l,mid);
        pair<ld,vector<Point>> right_ans=solve(mid+1,r);
        ld ans=min(left_ans.first,right_ans.first);
        ll p1=0,p2=0;
        while(p1<left_ans.second.size()-1 or p2<right_ans.second.size()-1){
            if(comp2(left_ans.second[p1],right_ans.second[p2])){
                ysorted.push_back(left_ans.second[p1]);
                if(p1<left_ans.second.size()-1){
                    p1++;
                }
            }else{
                ysorted.push_back(right_ans.second[p2]);
                if(p2<right_ans.second.size()-1){
                    p2++;
                }
            }
        }
        vector<Point> left_points,right_points;
        for(auto curr_point:ysorted){
            if(abs(a[mid].x-curr_point.x)<=ans+1){
                if(a[mid].x<curr_point.x){
                    if(right_points.size()!=0){
                        while(right_points.size()!=0 and right_points.back().x>curr_point.x){
                            ans=min(ans,dist(curr_point,right_points.back()));
                            right_points.pop_back();
                        }
                    }
                    for(auto itrv:right_points){
                        ans=min(ans,dist(curr_point,itrv));
                    }
                    for(auto itrv:left_points){
                        ans=min(ans,dist(curr_point,itrv));
                    }
                    right_points.push_back(curr_point);
                }else{
                    if(left_points.size()!=0){
                        while(left_points.size()!=0 and left_points.back().x>curr_point.x){
                            ans=min(ans,dist(curr_point,left_points.back()));
                            left_points.pop_back();
                        }
                    }
                    for(auto itrv:right_points){
                        ans=min(ans,dist(curr_point,itrv));
                    }
                    for(auto itrv:left_points){
                        ans=min(ans,dist(curr_point,itrv));
                    }
                    left_points.push_back(curr_point);
                }
            }
        }
        ysorted.push_back(*new Point(1e18,1e18));
        return {ans,ysorted};
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fstream myfile("C:/programs/closest_points/testcase.txt", ios_base::in);
    ll n;
    ll b;
    for(ll i=0;myfile>>b;i++){
        if(i==0){
            n=b;
        }else{
            if(i%2==0){
                a[(i-1)/2].y=b;
            }else{
                a[i/2].x=b;
            }
        }
    }
    /*
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    */
    sort(a,a+n,comp);
    pair<ld,vector<Point>> ans=solve(0,n-1);
    cout<<ans.first<<endl;
    return 0;
}
/*
4
1 1
2 10
10 2
3 3
2.82842

4
1 1
2 10
10 2
3 4
3.60555

4
1 1
2 10
10 2
3 5
4.47

5
1 0
2 10
10 2
3 7
3 3
3.16
*/
