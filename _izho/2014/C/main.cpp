#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=5e3+2;
vector<ll> adj[Size];
ll

void bfs(ll start_node){
    vector<bool> visited(Size,false);
    queue<ll> to_process;
    to_process.push(start_node);
    dist[start_node][start_node]={0,1};
    visited[start_node]=true;
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        for(auto itr:adj[curr_node]){
            if(visited[itr]==false){
                dist[start_node][itr]=dist[start_node][curr_node];
                dist[start_node][itr].first++;
                visited[itr]=true;
                to_process.push(itr);
                continue;
            }
            if(dist[start_node][itr].first>dist[start_node][curr_node].first){
                dist[start_node][itr].second+=dist[start_node][curr_node].second;
            }
        }
    }
}


void solve(){
    ll n;
    pair<ll,ll> ans={0,0};
    cin>>n;
    for(ll i=0;i<n;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(ll i=1;i<=n;i++){
        bfs(i);
        for(ll j=1;j<=n;j++){
            if(dist[i][j].first>ans.first){
                ans=dist[i][j];
            }else{
                if(dist[i][j].first==ans.first){
                    ans.second+=dist[i][j].second;
                }
            }
        }
    }
    cout<<ans.second/2<<endl;
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
