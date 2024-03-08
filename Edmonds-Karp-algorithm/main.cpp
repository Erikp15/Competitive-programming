#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll cap[10001][10001],n,m;
    vector<ll> neighbors[10001];
    vector<ll> all_nodes_passed;

ll bfs(ll s,ll t){
    queue<ll> next_node;
    ll previous[10001];
    for(ll i=0;i<=n;i++){
        previous[i]=0;
    }
    bool visited[10001];
    for(ll i=1;i<=n;i++)visited[i]=false;
    next_node.push(s);
    ll flow_so_far=1e18;
    while(!next_node.empty()){
        ll curr_node=next_node.front();
        next_node.pop();
        visited[curr_node]=true;
        if(curr_node==n){
            for(ll i=curr_node;i!=1;i=previous[i]){
                all_nodes_passed.push_back(i);
            }
            return flow_so_far;
        }
        for(ll i=1;i<=n;i++){
            if(cap[curr_node][i]>0 and visited[i]==false){
                flow_so_far=min(flow_so_far,cap[curr_node][i]);
                previous[i]=curr_node;
                next_node.push(i);
            }
        }
    }
    return -2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        cap[a][b]=w;
        neighbors[a].push_back(b);
    }
    ll flow=bfs(1,n);
    while(flow!=-2){
        cap[1][all_nodes_passed[all_nodes_passed.size()-1]]-=flow;
        cap[all_nodes_passed[all_nodes_passed.size()-1]][1]+=flow;
        for(ll i=(ll)all_nodes_passed.size()-2;i>=0;i--){
            cap[all_nodes_passed[i+1]][all_nodes_passed[i]]-=flow;
            cap[all_nodes_passed[i]][all_nodes_passed[i+1]]+=flow;
        }
        all_nodes_passed.clear();
        flow=bfs(1,n);
    }
    flow=0;
    for(ll i=1;i<n;i++){
        flow+=cap[n][i];
    }
    cout<<flow<<endl;
    return 0;
}
/*
6 9
1 2 7
1 3 4
2 4 5
2 5 3
3 2 3
3 5 2
4 6 8
5 4 3
5 6 5
10

4 5
1 2 5
1 3 5
2 3 5
2 4 5
3 4 5
10
*/
