#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=4e5+1;
    ll ans[Size],root[Size],t=1,components=0;
    pair<ll,ll> tout[Size];
    vector<ll> adj[Size],t_adj[Size],c_adj[Size];
    bool visited[Size],is_loop[Size],loop=false;

    void dfs_for_1(ll node){
        visited[node]=true;
        if(ans[node]<2){
            ans[node]++;
        }
        for(ll i=0;i<adj[node].size();i++){
            if(ans[adj[node][i]]<2){
                dfs_for_1(adj[node][i]);
            }
        }
    }

    void find_tout(ll node){
        visited[node]=true;
        for(ll i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                find_tout(adj[node][i]);
            }
        }
        tout[node].first=t;
        tout[node].second=node;
        t++;
    }

    void find_scc(ll node){
        visited[node]=true;
        for(ll i=0;i<t_adj[node].size();i++){
            if(!visited[t_adj[node][i]]){
                root[t_adj[node][i]]=root[node];
                find_scc(t_adj[node][i]);
            }
        }
    }

    void loop_test(ll node){
        for(ll i=0;i<(ll)adj[node].size();i++){
            if(root[node]==root[adj[node][i]]){
                is_loop[node]=true;
                return;
            }
        }
    }

    void make_infinite(ll node){
        stack<ll> to_search;
        to_search.push(node);
        while(!to_search.empty()){
            ll curr_node=to_search.top();
            to_search.pop();
            ans[curr_node]=-1;
            for(ll i=0;i<(ll)c_adj[curr_node].size();i++){
                ll next_node=c_adj[curr_node][i];
                to_search.push(next_node);
            }
        }
    }

    void find_infinite(ll node){
        if(is_loop[node]){
            ans[node]=-1;
            make_infinite(node);
            return;
        }
        for(ll i=0;i<(ll)c_adj[node].size();i++){
            ll next_node=c_adj[node][i];
            if(ans[next_node]!=-1){
                find_infinite(next_node);
            }
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            is_loop[i]=false;
            root[i]=0;
            tout[i].first=0;
            tout[i].second=0;
            ans[i]=0;
            adj[i].clear();
            t_adj[i].clear();
            c_adj[i].clear();
        }
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            t_adj[b].push_back(a);
        }
        dfs_for_1(1);
        for(ll i=1;i<=n;i++){
            visited[i]=false;
        }
        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                find_tout(i);
            }
        }
        sort(tout+1,tout+n+1);
        reverse(tout+1,tout+n+1);
        for(ll i=1;i<=n;i++){
            visited[i]=false;
        }
        for(ll i=1;i<=n;i++){
            if(!visited[tout[i].second]){
                components++;
                root[tout[i].second]=tout[i].second;
                find_scc(tout[i].second);
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<(ll)adj[i].size();j++){
                if(adj[i][j]==i){
                    loop=true;
                }
            }
        }
        if(components==n and !loop){
            for(ll i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
            return;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<(ll)adj[i].size();j++){
                if(root[i]!=root[adj[i][j]]){
                    c_adj[root[i]].push_back(root[adj[i][j]]);
                }
            }
        }
        for(ll i=1;i<=n;i++){
            if(root[i]==i){
                loop_test(i);
            }
        }
        find_infinite(1);
        for(ll i=1;i<=n;i++){
            if(root[i]==i and ans[i]==-1){
                stack<ll> to_search;
                to_search.push(i);
                while(!to_search.empty()){
                    ll curr_node=to_search.top();
                    to_search.pop();
                    ans[curr_node]=-1;
                    for(ll i=0;i<(ll)adj[curr_node].size();i++){
                        ll next_node=adj[curr_node][i];
                        if(ans[next_node]!=-1){
                            to_search.push(next_node);
                        }
                    }
                }
            }
        }
        for(ll i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
/*
1
6 7
1 4
1 3
3 4
4 5
2 1
5 5
5 6
*/
