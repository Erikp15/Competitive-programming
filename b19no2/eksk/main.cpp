#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+10;

ll parent[Size],ans_a[Size],ans_b[Size];
vector<ll> adj[Size],path;
bool visited[Size];

void dfs(ll curr_node){
    visited[curr_node]=true;
    for(auto itr:adj[curr_node]){
        if(!visited[itr]){
            parent[itr]=curr_node;
            dfs(itr);
        }
    }
}

ll find_depth(ll curr_node){
    visited[curr_node]=true;
    ll ans=0;
    for(auto itr:adj[curr_node]){
        if(!visited[itr]){
            ans=max(ans,find_depth(itr));
        }
    }
    return ans+1;
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0,from,to;i<n-1;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    ll a,b;
    cin>>a>>b;
    parent[a]=-1;
    dfs(a);
    path.push_back(0);
    for(ll i=0;i<=n;i++)visited[i]=0;
    for(ll i=b;i!=-1;i=parent[i]){
        path.push_back(i);
        visited[i]=1;
    }
    for(ll i=1;i<path.size();i++){
        ll curr=find_depth(path[i])-1;
        ans_b[i]=max(curr+i,ans_b[i-1]);
        ans_a[i]=curr+path.size()-i;
    }
    for(ll i=path.size()-1;i>=1;i--){
        ans_a[i]=max(ans_a[i],ans_a[i+1]);
    }
    ll ans=0;
    for(ll i=1;i<path.size();i++){
        ans=max(ans,min(ans_a[i+1],ans_b[i]));
    }
    cout<<ans<<endl;
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
/*
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

6
1 2
2 3
3 4
4 5
5 6
4 5
*/
