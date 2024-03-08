#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct garden{
    ll x,y,t;
};

bool comp(const garden& a,const garden& b){
    return a.t<b.t;
}

bool is_reachable(garden a,garden b){
    if(1){
        if(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y)>abs(a.t-b.t)*abs(a.t-b.t)){
            return false;
        }else{
            return true;
        }
    }else{
        if(abs(a.x-b.x)+abs(a.y-b.y)>abs(a.t-b.t)){
            return false;
        }else{
            return true;
        }
    }
}

const ll Size=1e5+10,mod=1e9+7;
garden g[Size],c[Size];
bool is_pos[Size];
ll n,q,ans=0;

ll b_search(ll l,ll r,ll i){
    ll mid=(l+r)/2;
    if(g[mid].t==c[i].t or (mid==0 and g[mid].t>=c[i].t)){
        return mid;
    }
    if(g[mid].t>=c[i].t and g[mid-1].t<=c[i].t){
        return mid;
    }
    if(g[mid].t>c[i].t){
        return b_search(l,mid,i);
    }else{
        return b_search(mid+1,r,i);
    }
}

void solve(){
    cin>>n>>q;
    g[n].t=2e9;
    c[q].t=2e9;
    for(ll i=0;i<n;i++){
        cin>>g[i].x>>g[i].y>>g[i].t;
    }
    for(ll i=0;i<q;i++){
        cin>>c[i].x>>c[i].y>>c[i].t;
    }
    sort(g,g+n,comp);
    g[n].t=2e18;
    for(ll i=0;i<q;i++){
        ll res=b_search(0,n,i);
        if(res==0){
            if(is_reachable(g[0],c[i])){
                ans++;
            }
        }else{
            if(is_reachable(g[res],c[i]) and is_reachable(g[res-1],c[i])){
                ans++;
            }
        }
    }
    cout<<q-ans<<endl;
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
/*
2 3
0 0 200
100 0 300
1 1 200
50 0 50
50 0 149

4 4
20 0 160
10 10 130
-10 10 200
0 0 100
50 51 0
5 5 115
0 0 201
100 100 500

1 1
0 0 100
10 10 200
*/
