#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;

vector<pair<ll,ll>> adj[Size];
bool visited[Size],has_edge[Size][Size];
ll flow=0;

ll max_flow(ll curr_node,ll prev_node,ll end_node,ll c_min){
    if(end_node==curr_node){
        flow+=c_min;
        return c_min;
    }
    visited[curr_node]=true;
    for(ll i=0;i<adj[curr_node].size();i++){
        pair<ll,ll> next_node=adj[curr_node][i];
        if(next_node.second!=0 and !visited[next_node.first]){
            ll ans=max_flow(next_node.first,curr_node,end_node,min(next_node.second,c_min));
            if(ans!=-1){
                adj[curr_node][i].second-=ans;
                for(ll j=0;j<adj[curr_node].size();j++){
                    if(adj[curr_node][j].first==prev_node){
                        adj[curr_node][j].second+=ans;
                    }
                }
                return ans;
            }
        }
    }
    return -1;
}

int main(){
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    for(ll i=0;i<m;i++){
        ll from,to,w;
        cin>>from>>to>>w;
        if(!has_edge[to][from]){
            adj[from].push_back({to,w});
            adj[to].push_back({from,0});
            has_edge[from][to]=true;
            has_edge[to][from]=true;
        }else{
            for(ll j=0;j<adj[from].size();j++){
                if(adj[from][j].first==from){
                    adj[from][j].second=w;
                }
            }
        }
    }
    for(ll i=0;i<adj[s].size();i++){
        ll ans=max_flow(adj[s][i].first,s,t,adj[s][i].second);
        adj[s][i].second-=ans;
        while(ans!=-1 and adj[s][i].second!=0){
            for(ll i=0;i<=n;i++){
                visited[i]=false;
            }
            ans=max_flow(adj[s][i].first,s,t,adj[s][i].second);
            adj[s][i].second-=ans;
        }
        for(ll i=0;i<=n;i++){
            visited[i]=false;
        }
    }
    cout<<flow<<endl;
    return 0;
}
/*
6 9 1 5
1 2 2
1 3 1
2 4 4
3 2 1
3 4 1
4 5 1
4 6 3
6 5 3
5 3 3
3

4 5 1 4
1 2 1
1 3 1
2 3 1
2 4 1
3 4 1

3 4
3 2
3 1 64
3 2 26
1 3 114
1 2 79
90
*/
