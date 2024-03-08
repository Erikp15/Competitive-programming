#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class edge{
public:
    ll from,to,weight;
    bool operator<(const edge& a){
        return weight<a.weight;
    }
};

    const ll Size=100001;
    ll n,m,q;
    vector<edge> adj;
    ll root[Size],depth[Size];

void make_set(ll v){
    root[v]=v;
    depth[v]=1;
}

ll find_set(ll v){
    if(root[v]==v)return v;
    root[v]=find_set(root[v]);
    return root[v];
}

void union_set(ll a,ll b){
    a=find_set(a);
    b=find_set(b);
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    root[b]=a;
    depth[a]=max(depth[b]+1,depth[a]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tree_weight=0;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        edge a;
        cin>>a.from>>a.to>>a.weight;
        adj.push_back(a);
    }
    sort(adj.begin(),adj.end());
    for(ll i=1;i<=n;i++){
        make_set(i);
    }
    for(ll i=0;i<adj.size();i++){
        if(find_set(adj[i].from)!=find_set(adj[i].to)){
            union_set(adj[i].from,adj[i].to);
            tree_weight+=adj[i].weight;
        }
    }
    cout<<tree_weight<<endl;
    return 0;
}
/*
6 9
5 4 9
5 1 4
1 4 1
1 2 2
4 3 5
4 2 3
2 3 3
2 6 7
3 6 8
17
*/
