#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
vector<ll> adj[Size],cond_adj[Size];
ll tin[Size],low[Size],comp[Size],comp_size[Size],timer=1,comps=1;
bool is_art_point[Size],visited[Size];

void find_art(ll curr_v,ll prev_v){
    visited[curr_v]=true;
    tin[curr_v]=low[curr_v]=timer++;
    ll children_passed=0;
    for(auto itr:adj[curr_v]){
        if(itr==prev_v)continue;
        if(visited[itr]){
            low[curr_v]=min(low[curr_v],low[itr]);
        }else{
            find_art(itr,curr_v);
            if(low[itr]>=tin[curr_v] and prev_v!=-1){
                is_art_point[curr_v]=true;
            }
            children_passed++;
        }
    }
    if(prev_v==-1 and children_passed>1){
        is_art_point[curr_v]=true;
    }
}

void comp_graph(ll curr_v){
    visited[curr_v]=true;
    comp[curr_v]=comps;
    comp_size[comps]++;
    for(auto itr:adj[curr_v]){
        if(!visited[itr]){
            comp_graph(itr);
        }
    }
}

ll dfs(ll curr_comp,ll value){
    visited[curr_comp]=true;
    ll ans=value;
    for(auto itr:cond_adj[curr_comp]){
        if(!visited[itr]){
            ans=max(ans,dfs(itr,value+comp_size[itr]));
        }
    }
    return ans;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            find_art(i,-1);
        }
        if(!is_art_point[i])visited[i]=false;
    }
    for(ll i=1;i<=n;i++){
        if(is_art_point[i]){
            comp[i]=comps;
            comp_size[comps]++;
            comps++;
        }
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            comp_graph(i);
            comps++;
        }
    }
    for(ll i=1;i<=comps;i++){
        visited[i]=false;
    }
    for(ll i=1;i<=n;i++){
        for(auto itr:adj[i]){
            if(comp[i]!=comp[itr]){
                cond_adj[comp[i]].push_back(comp[itr]);
            }
        }
    }
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        ll a;
        cin>>a;
        cout<<dfs(comp[a],comp_size[comp[a]])<<" ";
        for(ll i=1;i<=comps;i++){
            visited[i]=false;
        }
    }
    cout<<"\n";
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
