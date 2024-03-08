#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e3+10,mod=1e9+7;

vector<pair<ll,ll>> adj[Size];
ll dist[Size][Size],ans[Size];
bool visited[Size];

void bfs(ll start_node){
    queue<ll> to_process;
    to_process.push(start_node);
    visited[start_node]=1;
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        for(auto itr:adj[curr_node]){
            if(!visited[itr.first]){
                to_process.push(itr.first);
                dist[start_node][itr.first]=dist[start_node][curr_node]+itr.second;
                dist[itr.first][start_node]=dist[start_node][itr.first];
                visited[itr.first]=1;
            }
        }
    }
}

bool dfs(ll start_node,ll curr_node,ll end_node){
    if(curr_node==end_node){
        ans[curr_node]+=dist[start_node][end_node];
        return 1;
    }
    for(auto itr:adj[curr_node]){
        if(!visited[itr.first]){
            visited[itr.first]=1;
            if(dfs(start_node,itr.first,end_node)){
                ans[curr_node]+=dist[start_node][end_node];
                return 1;
            }
        }
    }
    return 0;
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0,from,to,w;i<n-1;i++){
        cin>>from>>to>>w;
        adj[from].push_back({to,w});
        adj[to].push_back({from,w});
    }
    for(ll i=1;i<=n;i++){
        bfs(i);
        for(ll j=1;j<=n;j++)
            visited[j]=0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<i;j++){
            visited[i]=1;
            dfs(i,i,j);
            for(ll k=1;k<=n;k++)
                visited[k]=0;
        }
        for(ll j=i+1;j<=n;j++){
            visited[i]=1;
            dfs(i,i,j);
            for(ll k=1;k<=n;k++)
                visited[k]=0;
        }
    }
    for(ll i=1;i<=n;i++)
        cout<<ans[i]/2<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
6
1 2 3
1 4 5
3 4 7
4 5 9
4 6 10
*/
