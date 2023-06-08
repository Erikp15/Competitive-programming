#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct edge{
    ll takeoff,to,landing;
    bool visited;
    edge(){
        visited=false;
    }
};

bool comp(const edge& a,const edge& b){
    return a.takeoff>b.takeoff;
}

const ll Size=2e5+1,mod=1e9+7;
ll n,m,ans[Size],offset[Size],processed[Size];
vector<edge> adj[Size];

void dfs(ll curr_node,ll depth){
    for(;processed[curr_node]<adj[curr_node].size();){

        edge next_node=adj[curr_node][processed[curr_node]];
        if(depth==1){
            if(ans[curr_node]<=next_node.takeoff){
                ans[next_node.to]=min(ans[next_node.to],next_node.landing);
                processed[curr_node]++;
                dfs(next_node.to,depth+1);
            }else{
                return;
            }
        }else{
            if(ans[curr_node]+offset[curr_node]<=next_node.takeoff){
                ans[next_node.to]=min(ans[next_node.to],next_node.landing);
                processed[curr_node]++;
                dfs(next_node.to,depth+1);
            }else{
                return;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll from,to,tin,tout;
        cin>>from>>tin>>to>>tout;
        edge tmp;
        tmp.landing=tout;
        tmp.takeoff=tin;
        tmp.to=to;
        adj[from].push_back(tmp);
    }
    for(ll i=1;i<=n;i++){
        cin>>offset[i];
        ans[i]=1e18;
        sort(adj[i].begin(),adj[i].end(),comp);
    }
    ans[1]=0;
    dfs(1,1);
    for(ll i=1;i<=n;i++){
        if(ans[i]==1e18){
            cout<<-1<<endl;
        }else{
            cout<<ans[i]<<endl;
        }
    }
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
