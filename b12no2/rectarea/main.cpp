#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=110;

class point{
public:
    ll x,y;
};

class square{
public:
    point tl,tr,bl,br;
};

bool comp(const ticket& a,const ticket& b){
    return a.from<b.from;
}

square squares[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        point p1,p2;
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        square[i].tl.x=min(p1.x,p2.x);
        square[i].tl.y=min(p1.y,p2.y);
        square[i].tr.x=max(p1.x,p2.x);
        square[i].tr.y=min(p1.y,p2.y);
        square[i].bl.x=min(p1.x,p2.x);
        square[i].bl.y=max(p1.y,p2.y);
        square[i].br.x=max(p1.x,p2.x);
        square[i].br.y=max(p1.y,p2.y);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
