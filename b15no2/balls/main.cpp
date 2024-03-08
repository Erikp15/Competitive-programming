#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll,ll> root,Size,depth,all_nodes;
set<ll> trees;

void create_node(ll node){
    root[node]=node;
    depth[node]=1;
    Size[node]=1;
}
ll find_root(ll node){
    ll r=root[node];
    if(r==node){
        return node;
    }
    return root[node]=find_root(r);
}
void merge_nodes(ll node1,ll node2){
    node1=find_root(node1);
    node2=find_root(node2);
    if(node1==node2)return;
    if(depth[node1]<depth[node2])swap(node1,node2);
    root[node2]=node1;
    depth[node1]=max(depth[node1],depth[node2]+1);
    Size[node1]=Size[node1]+Size[node2];
}

void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans=n;
    for(ll i=0,from,to;i<m;i++){
        cin>>from>>to;
        if(all_nodes[from]!=1e18){
            create_node(from);
            all_nodes[from]=1e18;
        }
        if(all_nodes[to]!=1e18){
            create_node(to);
            all_nodes[to]=1e18;
        }
        merge_nodes(from,to);
    }
    for(auto itr:root){
        trees.insert(find_root(itr.second));
    }
    for(auto itr:trees){
        ans=ans-Size[itr]+1;
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
