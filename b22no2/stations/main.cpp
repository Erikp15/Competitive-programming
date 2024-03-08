#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;

bool visited[Size];
vector<pair<ll,ll>> adj[Size];
ll degree[Size],kids[Size],path_sum_below[Size],ans[Size],processed_count=0;
ll kids_above[Size],path_sum_above[Size];
void reset_visited(ll n){
    for(ll i=1;i<=n;i++)
        visited[i]=0;
}
void bfs(ll start_node){
    queue<ll> to_process;
    to_process.push(start_node);
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=1;
        for(auto itr:adj[curr_node]){
            if(!visited[itr.first]){
                ll path_count=kids[curr_node]+kids_above[curr_node]-kids[itr.first]-1;
                ll curr_sum_below=(path_sum_below[itr.first]+kids[itr.first]*itr.second);
                ans[curr_node]+=curr_sum_below*path_count;
                path_sum_above[itr.first]=(path_sum_below[curr_node]+path_sum_above[curr_node]-curr_sum_below)+(path_count+1)*itr.second;
                kids_above[itr.first]=path_count+1;
                to_process.push(itr.first);
            }else{
                ll path_count=kids[curr_node]-1;
                ans[curr_node]+=path_sum_above[curr_node]*path_count;
            }
        }
        ans[curr_node]+=path_sum_below[curr_node]+path_sum_above[curr_node];
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0,from,to,weight;i<n-1;i++){
        cin>>from>>to>>weight;
        adj[from].push_back({to,weight});
        adj[to].push_back({from,weight});
        degree[from]++;
        degree[to]++;
    }
    queue<ll> to_process;
    for(ll i=1;i<=n;i++){
        kids[i]=1;
        if(degree[i]==1){
            to_process.push(i);
            visited[i]=1;
        }
    }
    while(true){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=1;
        processed_count++;
        for(auto itr:adj[curr_node]){
            if(!visited[itr.first]){
                kids[itr.first]+=kids[curr_node];
                path_sum_below[itr.first]+=kids[curr_node]*itr.second+path_sum_below[curr_node];
                degree[itr.first]--;
                if(degree[itr.first]==1){
                    to_process.push(itr.first);
                }
            }
        }
        if(processed_count==n-1)break;
    }
    reset_visited(n);
    ll mid=to_process.front();
    bfs(mid);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
5
1 2 10
 10
4 3 10
4 5 10

7
1 3 1
2 3 1
4 6 1
5 6 1
3 7 1
6 7 1



*/
