#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;

vector<ll> adj[Size];
bool visited[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

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
