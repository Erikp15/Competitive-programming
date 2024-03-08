#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+2;
ll l[Size],r[Size],val[Size];
vector<ll> adj[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        val[i]=l[i];
    }
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        ll more=0,fewer=0;
        for(auto itr:adj[i]){
            if(){}
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
111674811
646644446
*/
