#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
ll p[Size],v[Size],neighbors[Size];
bool visited[Size];
ll ans=0;
ll n;

void bfs(){
    queue<ll> to_process;
    for(ll i=1;i<=n;i++){
        if(neighbors[i]==1){
            to_process.push(i);
            visited[i]=true;
        }
    }
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        ans+=v[curr_node];
        neighbors[p[curr_node]]--;
        if(neighbors[p[curr_node]]==1 and !visited[p[curr_node]]){
            to_process.push(p[curr_node]);
            visited[p[curr_node]]=true;
        }
    }
}

ll dfs(ll curr_node){
    visited[curr_node]=true;
    ans+=v[curr_node];
    ll smallest=v[curr_node];
    if(!visited[p[curr_node]])
        smallest=min(smallest,dfs(p[curr_node]));
    return smallest;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>p[i]>>v[i];
        neighbors[i]++;
        neighbors[p[i]]++;
    }
    bfs();
    ll smallest=1e18;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            ll smallest=dfs(i);
            ans-=smallest;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
2 10
3 20
4 30
1 40
90

5
2 40
1 50
4 50
3 40
1 50
*/
