#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+10;

ll dist[Size];
vector<ll> adj[Size],rev_adj[Size];
set<pair<ll,ll>> to_process;
bool visited[Size];

void dijkstra(ll start_node){
    while(!to_process.empty()){
        pair<ll,ll> curr_node=*to_process.begin();
        if(curr_node.first==1e18)break;
        to_process.erase(curr_node);
        for(auto itr:adj[curr_node.second]){
            if(dist[curr_node.second]<dist[itr]){
                to_process.erase({dist[itr],itr});
                dist[itr]=dist[curr_node.second];
                to_process.insert({dist[itr],itr});
            }
        }
        for(auto itr:rev_adj[curr_node.second]){
            if(dist[curr_node.second]+1<dist[itr]){
                to_process.erase({dist[itr],itr});
                dist[itr]=dist[curr_node.second]+1;
                to_process.insert({dist[itr],itr});
            }
        }
    }
}

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    for(ll from,to;cin>>from>>to;){
        adj[from].push_back(to);
        rev_adj[to].push_back(from);
    }
    to_process.insert({-1,a});
    for(ll i=1;i<=n;i++){
        dist[i]=1e18;
        if(i!=a){
            to_process.insert({1e18,i});
        }
    }
    dist[a]=0;
    dijkstra(a);
    if(dist[b]==1e18){
        cout<<"X"<<endl;
    }else{
        cout<<dist[b]<<endl;
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
