#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll ans[Size],all2=0;
vector<ll> adj[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0,from,to;i<n-1;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(ll i=1;i<=n;i++){
        all2+=n-adj[i].size()-1;
    }
    all2/=2;
    for(ll i=1;i<=n;i++){
        ans[i]+=all2;
        ll rem=(n-adj[i].size()-1);
        for(ll j=0;j<adj[i].size();j++){
            ll curr=adj[i][j];
            rem+=(n-adj[curr].size()-1)-j;
        }
        ans[i]-=rem;
    }
    ll a=0;
    for(ll i=1;i<=n;i++){
        a+=ans[i];
    }
    cout<<a/3<<endl;
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
