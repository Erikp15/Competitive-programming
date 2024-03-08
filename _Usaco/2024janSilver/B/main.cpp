#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=1e5+1;

vector<ll> adj[Size];
ll potions[Size];
ll sub_leafs[Size], potion_count[Size], ans[Size];
bool visited[Size];

void dfs(ll curr_node){
    visited[curr_node]=1;
    if(adj[curr_node].size()==1 and curr_node!=1){
        sub_leafs[curr_node]=1;
    }
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node]){
            dfs(next_node);
            potion_count[curr_node]+=ans[next_node];
            sub_leafs[curr_node]+=sub_leafs[next_node];
        }
    }
    ans[curr_node]=min(sub_leafs[curr_node],potion_count[curr_node]);
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>potions[i];
    }
    for(ll i=0,from,to;i<n-1;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    ll leafs=0;
    for(ll i=2;i<=n;i++){
        if(adj[i].size()==1){
            leafs++;
        }
    }
    for(ll i=0;i<leafs;i++){
        potion_count[potions[i]]++;
    }
    dfs(1);
    /*
    for(ll i=1;i<=n;i++){
        cout<<sub_leafs[i]<<" ";
    }
    cout<<endl;
    for(ll i=1;i<=n;i++){
        cout<<potions[i]<<" ";
    }
    cout<<endl;
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    */
    cout<<ans[1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
