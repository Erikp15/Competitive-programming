#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    vector<ll> all_neighbors[1001];
    ll distance_from_to[1001][1001];
    bool visited[1001];

void bfs(){
    queue<ll> to_be_processed;
    to_be_processed.push(1);
    visited[1]=true;
    while(!to_be_processed.empty()){
        ll curr_node=to_be_processed.front();
        to_be_processed.pop();
        visited[curr_node]=true;
        for(ll i=0;i<(ll)all_neighbors[curr_node].size();i++){
            ll curr_neighbor=all_neighbors[curr_node][i];
            if(visited[curr_neighbor]){
                continue;
            }
            distance_from_to[1][curr_neighbor]=distance_from_to[1][curr_node]+1;
            to_be_processed.push(curr_neighbor);
        }

    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        all_neighbors[a].push_back(b);
        all_neighbors[b].push_back(a);
    }
    bfs();
    for(ll i=2;i<=n;i++){
        for(ll j=2;j<=n;j++){
            distance_from_to[i][j]=abs(distance_from_to[1][i]-distance_from_to[1][j]);
        }
    }
    ll k;
    cin>>k;
    for(ll i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        cout<<distance_from_to[a][b]<<endl;
    }
    return 0;
}
