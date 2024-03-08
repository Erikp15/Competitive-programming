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



    const ll Size=1e5+1,m=1e9+7;
    point p[Size],start_p;
    ll n;
    bool do_intersect(point a1,point a2,point b1,point b2){

    }
    void read(){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
        }
    }
    void solve(){
        ll x,y;
        cin>>x>>y;
        point end_p;
        end_p.x=-1e18; end_p.y=-1e18;
        for(ll i=1;i<n;i++){
            if(ccw(p[i-1],{y,x},p[i])){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=5;
    read();
    while(t--){
        solve();
    }
    return 0;
}
/*
5
1 1
3 1
5 5
6 4
1 3

*/
