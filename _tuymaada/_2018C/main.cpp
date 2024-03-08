#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class vertex{
public:
    ll i,v;
};
    bool operator >(const vertex& a,const vertex& b){
        return a.v>b.v;
    }

    const ll Size=1e6+1;
    ll tin[Size],root[Size],t=1,components=0,sinks=0,sources=0;
    vertex tout[Size];
    vector<ll> adj[Size],r_adj[Size],c_adj[Size],sources_to_false,sinks_to_false;
    bool visited[Size],is_sink[Size],is_source[Size];

    void find_tout(ll node){
        tin[node]=t;
        visited[node]=true;
        t++;
        for(ll i=0;i<(ll)adj[node].size();i++){
            if(!visited[adj[node][i]]){
                find_tout(adj[node][i]);
            }
        }
        tout[node].i=node;
        tout[node].v=t;
        t++;
    }

    void comp_build(ll node){
        visited[node]=true;
        for(ll i=0;i<(ll)r_adj[node].size();i++){
            if(!visited[r_adj[node][i]]){
                root[r_adj[node][i]]=root[node];
                comp_build(r_adj[node][i]);
            }
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            ll from,to;
            cin>>from>>to;
            adj[from].push_back(to);
            r_adj[to].push_back(from);
        }
        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                find_tout(i);
            }
        }
        sort(tout+1,tout+n+1,greater<vertex>());
        reverse(tout+1,tout+n+1);
        for(ll i=1;i<=n;i++)visited[i]=false;
        for(ll i=1;i<=n;i++){
            if(!visited[tout[i].i]){
                components++;
                root[tout[i].i]=tout[i].i;
                comp_build(tout[i].i);
            }
        }
        if(components==1 or m==1){
            cout<<0<<"\n";
            return;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<adj[i].size();j++){
                if(root[i]!=root[adj[i][j]]){
                    c_adj[root[i]].push_back(root[adj[i][j]]);

                }
            }
        }
        for(ll i=1;i<=n;i++)visited[i]=false;
        for(ll i=1;i<=n;i++){
            if(root[i]==i){
                if(c_adj[i].empty()){
                    is_sink[i]=true;
                    continue;
                }
                is_source[i]=true;
                sinks_to_false.push_back(i);
                for(ll j=0;j<(ll)c_adj[i].size();j++){
                    is_sink[c_adj[i][j]]=true;
                    sources_to_false.push_back(c_adj[i][j]);
                }
            }
        }
        for(auto itrv:sources_to_false){
            is_source[itrv]=false;
        }
        for(auto itrv:sinks_to_false){
            is_sink[itrv]=false;
        }
        for(ll i=1;i<=n;i++){
            if(is_sink[i] and !is_source[i]){
                sinks++;
            }
            if(!is_sink[i] and is_source[i]){
                sources++;
            }
        }
        cout<<max(sinks,sources)<<"\n";
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
9 11
1 2
2 3
3 1
4 5
5 6
6 4
7 8
8 9
9 7
1 4
1 7
2

9 9
1 2
2 3
3 1
4 5
5 6
6 4
7 8
8 9
9 7
3
*/
