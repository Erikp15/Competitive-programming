#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll n,m,t,value[Size],best[Size],second[Size],leaf[Size];
bool visited[Size];
vector<ll> adj[Size];

void top_down(ll curr_node,ll prev_node){
    visited[curr_node]=true;
    if(best[curr_node]==best[prev_node]-value[curr_node]){
        if(second[prev_node]+value[prev_node]>second[curr_node] and second[prev_node]+value[prev_node]<=best[curr_node]){
            second[curr_node]=second[prev_node]+value[prev_node];
        }
        if(second[prev_node]+value[prev_node]>best[curr_node]){
            second[curr_node]=best[curr_node];
            best[curr_node]=second[prev_node]+value[prev_node];
        }
    }else{
        if(best[prev_node]+value[prev_node]>second[curr_node] and best[prev_node]+value[prev_node]<=best[curr_node]){
            second[curr_node]=best[prev_node]+value[prev_node];
        }
        if(best[prev_node]+value[prev_node]>best[curr_node]){
            second[curr_node]=best[curr_node];
            best[curr_node]=best[prev_node]+value[prev_node];
        }
    }
    for(ll i=0;i<adj[curr_node].size();i++){
        ll next_node=adj[curr_node][i];
        if(!visited[next_node]){
            top_down(next_node,curr_node);
        }
    }
}

ll bottom_up(){
    queue<ll> to_process;
    for(ll i=1;i<=n;i++){
        if(leaf[i]==1){
            to_process.push(i);
        }
    }
    ll mid=1;
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        mid=to_process.front();
        to_process.pop();
        for(ll i=0;i<adj[curr_node].size();i++){
            ll next_node=adj[curr_node][i];
            if(!visited[next_node]){
                leaf[next_node]--;
                if(leaf[next_node]==1){
                    to_process.push(next_node);
                }
            }
            if(visited[next_node]){
                if(best[next_node]+value[next_node]>second[curr_node] and best[next_node]+value[next_node]<=best[curr_node]){
                    second[curr_node]=best[next_node]+value[next_node];
                }
                if(best[next_node]+value[next_node]>best[curr_node]){
                    second[curr_node]=best[curr_node];
                    best[curr_node]=best[next_node]+value[next_node];
                }
            }
        }
        visited[curr_node]=true;
    }
    return mid;
}

void solve(){
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
        leaf[from]++;
        leaf[to]++;
    }
    cin>>m;
    for(ll i=0;i<m;i++){
        ll id;
        cin>>id;
        cin>>value[id];
    }
    ll mid=bottom_up();
    for(ll i=1;i<=n;i++){
        visited[i]=false;
    }
    visited[mid]=true;
    for(ll i=0;i<adj[mid].size();i++){
        top_down(adj[mid][i],mid);
    }
    cin>>t;
    while(t--){
        ll id;
        cin>>id;
        cout<<best[id]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}
/*
4
1 2
2 3
3 4
4
1 10
2 1
3 4
4 4

5
1 3
2 3
3 4
4 5
5
1 1
2 1
3 2
4 0
5 5
*/
