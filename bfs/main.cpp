#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll const Size=2e5+1;
    vector<ll> adj[Size];
    bool visited[Size];
    ll dist[Size];

    void bfs(pair<ll,ll> start_node){
        queue<pair<ll,ll>> to_p;
        to_p.push(start_node);
        while(!to_p.empty()){
            pair<ll,ll> node=to_p.front();
            to_p.pop();
            if(visited[node.first]){
                continue;
            }
            visited[node.first]=true;
            dist[node.first]=node.second;
            for(auto it:adj[node.first]){
                if(!visited[it]){
                    to_p.push({it,node.second+1});
                }
            }
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
        bfs({1,0});
        for(ll i=1;i<=n;i++){
            cout<<dist[i]<<endl;
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
1
7 5
1 2
1 3
2 3
2 4
3 5
*/
