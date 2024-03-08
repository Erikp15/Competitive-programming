#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    vector<ll> all_neighbors[10001];
    bool visited[10001],color[10001];

int bfs(){
    queue<ll> to_be_processed;
    to_be_processed.push(1);
    visited[1]=true;
    while(!to_be_processed.empty()){
        ll curr_node=to_be_processed.front();
        visited[curr_node]=true;
        for(ll i=0;i<(ll)all_neighbors[curr_node].size();i++){
            ll curr_neighbor=all_neighbors[curr_node][i];
            if(visited[curr_neighbor]){
                if(color[curr_neighbor]==color[curr_node]){
                    cout<<"false"<<endl;
                    return 0;
                }
                continue;
            }
            color[curr_neighbor]=(color[curr_node]*-1)+1;
            to_be_processed.push(curr_neighbor);
        }
    }
    cout<<"true"<<endl;
    return 0;
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
    return 0;
}
/*
0 1
1 2
2 8
8 5
5 6
6 9
9 3
4 7
7 9
0 3
7 0
*/
