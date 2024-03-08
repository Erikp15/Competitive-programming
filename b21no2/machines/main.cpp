#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e4+1,m=1e9+7;
ll lines[100][Size];
vector<ll> adj[Size];
bool exists[Size];
int visited[Size];

bool dfs(ll curr_node){
    visited[curr_node]=1;
    for(auto itr:adj[curr_node]){
        if(visited[itr]==1){
            return true;
        }
        if(visited[itr]==0){
            if(dfs(itr)){
                return true;
            }
        }
    }
    visited[curr_node]=2;
    return false;
}

void solve(){
    for(ll i=0;i<=Size;i++){
        visited[i]=0;
        adj[i].clear();
        exists[i]=false;
    }
    ll k;
    cin>>k;
    for(ll i=0,s;i<k;i++){
        cin>>s;
        if(s!=0){
            cin>>lines[i][0];
            exists[lines[i][0]]=true;
        }
        for(ll j=1;j<s;j++){
            cin>>lines[i][j];
            adj[lines[i][j-1]].push_back(lines[i][j]);
            exists[lines[i][j]]=true;
        }
    }
    for(ll i=1;i<Size;i++){
        if(!visited[i] and exists[i]){
            if(dfs(i)){
                cout<<0<<endl;
                return;
            }
        }
    }
    cout<<1<<endl;
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
