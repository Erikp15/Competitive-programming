#include <iostream>

using namespace std;

typedef long long ll;

class edge{
    ll e,w;
    bool operator <(edge& a){
        return w<a.w;
    }
};
    ll n,m,total_length=0;
    set<edge> adj[1001];
    vector<edge> adj_mst[1001];

void mst(ll start_node){
    for(ll j=0;j<n;j++){
        for(ll i=1;i<=n;i++){
            if(!adj_mst.empty() or i==start_node){
                ll e=*adj[i].begin().e;
                edge s; s.e=e; s.w=*adj[i].begin().w;
                adj_mst[i].push_back(adj[i].begin());
                adj_mst[e].push_back();
                total_length+=*adj[i].begin().w;
                adj[i].remove(adj[i].begin());
                adj[e].remove(s);
                break;
            }
        }
    }
}

int main(){
    ll n>>m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        edge a; cin>>a.e;
        edge b; cin>>b.e>>b.w;
        a.w=b.w;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    mst(1);
    cout << "Hello world!" << endl;
    return 0;
}
