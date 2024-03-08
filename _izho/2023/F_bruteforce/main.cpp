#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct edge{
    ll to,l,r;
};

const ll Size=1e2+1;
vector<edge> adj[Size];
bool visited[Size];
ll n,m;

void reset_visited(){
    for(ll i=1;i<=n;i++){
        visited[i]=false;
    }
}

void dfs(ll curr_node,ll time){
    visited[curr_node]=true;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node.to] and next_node.l<=time and next_node.r>=time){
            dfs(next_node.to,time);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    srand(1);
    for(ll i=0;i<m;i++){
        ll from,to,l,r;
        //cin>>from>>to>>l>>r;
        from=i+1; to=i+2;
        l=rand()/1000;
        r=rand()/1000;
        if(l>r)
            swap(l,r);
        edge tmp;
        tmp.to=to;
        tmp.l=l;
        tmp.r=r;
        adj[from].push_back(tmp);
        tmp.to=from;
        adj[to].push_back(tmp);
    }
    ll q=n;
    //cin>>q;
    while(q--){
        ll from,to,l,r;
        //cin>>from>>to>>l>>r;
        from=1; to=n;
        l=0; r=q;
        ll ans=0;
        for(ll i=l;i<=r;i++){
            dfs(from,i);
            if(visited[to]){
                ans++;
            }
            reset_visited();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
5 4
1 2 1 3
2 3 3 4
3 4 1 5
4 5 3 4
10
1 3 3 3


4 3
1 2 2 5
2 3 1 4
3 4 2 3
3
1 3 1 5
4 2 2 4
1 4 3 6

3 2
1 2 1 50000
2 3 2 4000
10
1 3 1 131234
1 3 1 232321
1 3 1 3321
1 3 1 423
1 3 2311 35435
1 3 1 6192
1 3 0 1000000
*/
