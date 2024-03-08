#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll const Size=2e5+1;
    vector<ll> adj[Size];
    bool visited[Size];
    ll comp=0;

    void dfs(ll node){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it])dfs(it);
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                comp++;
                dfs(i);
            }
        }
        cout<<comp<<endl;
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
1
7 5
1 2
1 3
2 3
2 4
3 5
*/
