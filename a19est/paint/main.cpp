#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e5+1;

ll num_trucks[Size];
vector<pair<ll,ll>> adj[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>num_trucks[i];
    }
    for(ll i=0;i<n-1;i++){
        ll from,to,value;
        cin>>from>>to>>value;
        adj[from].push_back({to,value});
        adj[to].push_back({from,value});
        ans+=value;
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

