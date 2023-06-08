#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+10, p=1e9+7;

class edge{
public:
    ll f,t,c;
    edge(ll f,ll t,ll c): f(f), t(t), c(c) {}
};

vector<ll> adj[Size];
ll ans=0;
ll s=0;
vector<edge> edges;
vector<pair<ll,ll>> match;
ll l,r,m;
ll tar_node;
bool match_l[Size],match_r[Size];
ll ptr[Size],depth[Size];


void add_edge(ll v, ll u, ll cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(s);
    adj[u].push_back(s+1);
    s+=2;
}

void bfs(ll start_node){
    queue<ll> to_process;
    to_process.push(start_node);
    depth[start_node]=0;
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        for(ll i=0;i<adj[curr_node].size();i++){
            ll next_node=adj[curr_node][i];
            if(edges[next_node].c<1)
                continue;
            if(depth[edges[next_node].t]!=-1)
                continue;
            depth[edges[next_node].t]=depth[curr_node]+1;
            to_process.push(edges[next_node].t);
        }
    }
}

ll dfs(ll curr_node, ll flow){
    if(flow==0 or curr_node==tar_node)
        return flow;
    for(ll& i = ptr[curr_node];i<adj[curr_node].size();i++){
        ll next_node=adj[curr_node][i];
        if(depth[edges[next_node].t]!=depth[curr_node]+1 or edges[next_node].c<=0)
            continue;
        ll ret=dfs(edges[next_node].t, min(flow,edges[next_node].c));
        if(ret==0)
            continue;
        edges[next_node].c -= ret;
        edges[next_node ^ 1].c += ret;
        if(curr_node<l and edges[next_node].t>=l and edges[next_node].t<l+r){
            match_l[curr_node]=edges[next_node].t;
            match_r[edges[next_node].t]=curr_node;
        }
        return ret;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>r>>m;
    for(ll i=0;i<m;i++){
        ll from,to;
        cin>>from>>to;
        to+=l;
        add_edge(from,to,1);
    }
    ll n=l+r;
    tar_node=n+1;
    for(ll i=0;i<l;i++){
        add_edge(n,i,1);
    }
    for(ll i=l;i<l+r;i++){
        add_edge(i,n+1,1);
    }
    for(ll i=0;i<=n+1;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    while(true){
        for(ll i=0;i<=n+2;i++){
            depth[i]=-1;
        }
        bfs(n);
        if(depth[n+1]==-1)
            break;
        for(ll i=0;i<=n+2;i++){
            ptr[i]=0;
        }
        while(ll flow=dfs(n,1e18)){
            ans+=flow;
        }
    }
    cout<<ans<<"\n";
    vector<pair<ll,ll>> pri;
    for(ll i=0;i<n;i++){
        if(match_l[i]>=0)
            pri.emplace_back(i,match_l[i]);
    }
    for(ll i=0;i<pri.size();i++){
        cout<<pri[i].first<<" "<<pri[i].second-l<<"\n";
    }
    return 0;
}
/*
4 4 7
1 1
2 2
0 0
3 1
1 2
2 0
3 2

3
0 0
1 1
2 2
*/
