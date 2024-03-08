#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const Size=2e5+1;
vector<pair<ll,ll>> adj[Size];
bool visited[Size];
ll dist[Size],m;

void dijkstra(ll s){
    for(ll i=1;i<=n;i++){
        dist[i]=1e18;
    }
    dist[s]=0;
    to_process.insert({dist[s],s});
    while(!to_process.empty()){
        pair<ll,ll> curr_node = *to_process.begin();
        to_process.erase(curr_node);
        for(auto edge:adj[curr_node.second]) {
            ll to=edge.first;
            ll len=edge.second;
            if(dist[curr_node.second]+len<dist[to]) {
                to_process.erase({dist[to],to});
                dist[to]=dist[curr_node.second]+len;
                to_process.insert({dist[to],to});
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dijkstra(1);
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
1 2 3
1 3 8
2 3 3
2 4 1
3 5 10
*/
