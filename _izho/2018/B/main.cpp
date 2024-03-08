#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e5+1;

vector<pair<ll,ll>> adj[Size],mst[Size];
vector<pair<pair<ll,ll>,ll>> edges;
ll safety[Size],dist[Size];
bool visited[Size];
ll root[Size],ranking[Size],parent[Size];
ll n,m;

vector<ll> euler_tour;
ll seg_tree[3*Size],first[Size],depth[Size];
ll dist_from_root[Size];

void dfs(ll curr_node){
    visited[curr_node]=1;
    first[curr_node]=euler_tour.size();
    euler_tour.push_back(curr_node);
    for(ll i=0;i<mst[curr_node].size();i++){
        pair<ll,ll> next_node=mst[curr_node][i];
        if(!visited[next_node.first]){
            depth[next_node.first]=depth[curr_node]+1;
            dist_from_root[next_node.first]=min(dist_from_root[curr_node],)
            parent[next_node.first]=curr_node;
            dfs(next_node.first);
            euler_tour.push_back(curr_node);
        }
    }
}

void calc_dist_2_ancester(ll start_node,ll curr_node,ll ans){
    dist_2_ancester[start_node][curr_node]=ans;
    if(depth[curr_node]==0)
        return;
    calc_dist_2_ancester(start_node,parent[curr_node],min(ans,safety[parent[curr_node]]));
}

void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i]=euler_tour[l];
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        if(depth[seg_tree[i*2]]<depth[seg_tree[i*2+1]]){
            seg_tree[i]=seg_tree[i*2];
        }else{
            seg_tree[i]=seg_tree[i*2+1];
        }
    }
}

ll query(ll l,ll r,ll tl,ll tr,ll i){
    if(tl>r or tr<l)
        return -1;
    if(tl==l and tr==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        ll r1=query(l,mid,tl,min(tr,mid),i*2);
        ll r2=query(mid+1,r,max(tl,mid+1),tr,i*2+1);
        if(r1==-1){
            return r2;
        }
        if(r2==-1){
            return r1;
        }
        if(depth[r1]<depth[r2]){
            return r1;
        }else{
            return r2;
        }
    }
}

ll lca(ll node1,ll node2){
    node1=first[node1];
    node2=first[node2];
    if(node1>node2)
        swap(node1,node2);
    return query(0,euler_tour.size()-1,node1,node2,1);
}

void calc_danger(){
    set<pair<ll,ll>> to_process;
    for(ll i=1;i<=n;i++){
        to_process.insert({safety[i],i});
    }
    while(to_process.size()){
        pair<ll,ll> curr_node=*to_process.begin();
        to_process.erase(curr_node);
        while(to_process.size() and visited[curr_node.second]){
            curr_node=*to_process.begin();
            to_process.erase(curr_node);
        }
        visited[curr_node.second]=1;
        for(auto itr:adj[curr_node.second]){
            if(safety[itr.first]>safety[curr_node.second]+itr.second){
                to_process.erase({safety[itr.first],itr.first});
                safety[itr.first]=safety[curr_node.second]+itr.second;
                to_process.insert({safety[itr.first],itr.first});
            }
        }
    }
}

void add_node(ll node){
    root[node]=node;
    ranking[node]=1;
}

ll get_root(ll node){
    if(root[node]==node)
        return node;
    root[node]=get_root(root[node]);
    return root[node];
}

void tree_union(ll node1,ll node2){
    ll root1=get_root(node1);
    ll root2=get_root(node2);
    if(root1==root2)
        return;
    if(ranking[root1]<ranking[root2])
        swap(root1,root2);
    mst[node1].push_back({node2,safety[node2]});
    mst[node2].push_back({node1,safety[node1]});
    root[root2]=root1;
    ranking[root1]=max(ranking[root1],ranking[root2]+1);
}

ll dijkstra(ll start_node,ll end_node){
    set<pair<ll,ll>> to_process;
    for(ll i=1;i<=n;i++){
        if(i!=start_node){
            dist[i]=0;
        }else{
            dist[i]=safety[i];
        }
        to_process.insert({dist[i],i});
        visited[i]=0;
    }
    while(to_process.size()){
        pair<ll,ll> curr_node=*to_process.rbegin();
        to_process.erase(curr_node);
        while(to_process.size() and visited[curr_node.second]){
            curr_node=*to_process.rbegin();
            to_process.erase(curr_node);
        }
        visited[curr_node.second]=1;
        for(auto itr:adj[curr_node.second]){
            if(dist[itr.first]<min(dist[curr_node.second],itr.second)){
                to_process.erase({dist[itr.first],itr.first});
                dist[itr.first]=min(dist[curr_node.second],itr.second);
                to_process.insert({dist[itr.first],itr.first});
            }
        }
    }
    return dist[end_node];
}

void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        safety[i]=1e18;
        add_node(i);
    }
    for(ll i=0;i<m;i++){
        ll from,to,w;
        cin>>from>>to>>w;
        adj[from].push_back({to,w});
        adj[to].push_back({from,w});
    }
    ll k;
    cin>>k;
    for(ll i=0;i<k;i++){
        ll v;
        cin>>v;
        safety[v]=0;
    }
    calc_danger();
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<adj[i].size();j++){
            ll res=min(safety[i],safety[adj[i][j].first]);
            adj[i][j]={adj[i][j].first,res};
            edges.push_back({{res,adj[i][j].first},i});
        }
    }
    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());
    for(auto itr:edges){
        tree_union(itr.first.second,itr.second);
    }
    for(ll i=1;i<=n;i++){
        visited[i]=0;
    }
    dfs(get_root(1));
    build(0,euler_tour.size()-1,1);
    for(ll i=1;i<=n;i++){
        calc_dist_2_ancester(i,i,safety[i]);
    }
    ll q;
    cin>>q;
    while(q--){
        ll from,to;
        cin>>from>>to;
        ll ans=lca(from,to);
        ll from_2_lca=dist_from_root[from]-dist_from_root[ans];
        ll to_2_lca=dist_from_root[to]-dist_from_root[ans];
        cout<<min(from_2_lca,to_2_lca)<<"\n";
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
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5

*/
