#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class edge{
public:
    ll f,to,w;
};

    bool operator>(const edge& a,const edge& b){
        if(a.w<b.w){
            return true;
        }else{
            return false;
        }
    }

    const ll Size=1e2;
    vector<edge> adj;
    ll tree_weight=0;
    bool selected[Size];

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            edge a;
            cin>>a.f>>a.to>>a.w;
            adj.push_back(a);
        }
        selected[1]=true;
        cout<<endl;
        sort(adj.begin(),adj.end(),greater<edge>());
        for(ll i=0;i<adj.size();i++){
            cout<<adj[i].f<<adj[i].to<<adj[i].w<<endl;
        }
        cout<<endl;
        for(ll i=0;i<n-1;i++){
            for(ll j=0;j<adj.size();j++){
                if((selected[adj[j].to] and !selected[adj[j].f])){
                    selected[adj[j].f]=true;
                    cout<<adj[j].f<<adj[j].to<<adj[j].w<<endl;
                    tree_weight+=adj[j].w;
                    break;
                }
                if((selected[adj[j].f] and !selected[adj[j].to])){
                    selected[adj[j].to]=true;
                    cout<<adj[j].f<<adj[j].to<<adj[j].w<<endl;
                    tree_weight+=adj[j].w;
                    break;
                }
            }
        }
        cout<<tree_weight<<endl;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
6 9
5 1 4
5 4 9
1 4 1
1 2 2
4 2 3
4 3 5
3 6 8
2 3 3
2 6 7
*/
