#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,m;
    vector<ll> adj[100001];
    bool visited[100001],colored[100001];

bool is_bipartite(){
    queue<ll> to_be_proc;
    to_be_proc.push(1);
    colored[1]=1;
    while(!to_be_proc.empty()){
        ll curr_node=to_be_proc.front();
        to_be_proc.pop();
        visited[curr_node]=true;
        for(ll i=0;i<adj[curr_node].size();i++){
            ll next_node=adj[curr_node][i];
            if(visited[next_node]){
                if(colored[next_node]==colored[curr_node]){
                    return 0;
                }
            }else{
                colored[next_node]=!colored[curr_node];
                to_be_proc.push(next_node);
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b; cin>>a; cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<is_bipartite()<<endl;
    return 0;
}
