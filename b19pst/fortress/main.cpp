#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e4+1;

set<pair<ll,ll>> to_process;
ll dist[Size];
vector<pair<ll,ll>> adj[Size];
bool visited[Size];

void process(ll node){
    visited[node]=true;
    for(auto itr:adj[node]){
        ll neighbor=itr.first;
        ll weight=itr.second;
        if(!visited[neighbor]){
            to_process.erase({dist[neighbor],neighbor});
            dist[neighbor]=min(dist[neighbor],dist[node]+weight);
            to_process.insert({dist[neighbor],neighbor});
        }else{
            to_process.erase({dist[neighbor],neighbor});
        }
    }
}

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=0;i<m;i++){
        ll from,to,weight;
        cin>>from>>to>>weight;
        adj[from].push_back({to,weight});
        adj[to].push_back({from,weight});
    }
    to_process.insert({0,1});
    for(ll i=2;i<=n;i++){
        to_process.insert({1e18,i});
        dist[i]=1e18;
    }
    for(ll i=0;i<n;i++){
        auto next_node=*to_process.begin();
        if(next_node.second==1e18)break;
        to_process.erase(*to_process.begin());
        process(next_node.second);
    }
    cout<<dist[n]<<"\n";
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


