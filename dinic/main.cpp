#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e1+1, m=1e9+7;

vector<pair<ll,ll>> adj[Size];
ll depth[Size];
ll ans=0;
bool is_present[Size][Size];
bool visited[Size];

ll hashing(ll v,ll u){
    return (v*1000000+u)%m;
}

void bfs(ll start_node){
    queue<ll> to_process;
    to_process.push(start_node);
    depth[start_node]=1;
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        for(ll i=0;i<adj[curr_node].size();i++){
            pair<ll,ll> next_node=adj[curr_node][i];
            if(depth[next_node.first]==0 and next_node.second>0){
                depth[next_node.first]=depth[curr_node]+1;
                to_process.push(next_node.first);
            }
        }
    }
}

ll dfs(ll curr_node, ll tar_node, ll flow){
    visited[curr_node]=1;
    if(flow==0 or curr_node==tar_node)
        return flow;
    for(ll i=adj[curr_node]size()-1;i>=0;i--){
        pair<ll,ll> next_node=adj[curr_node][i];
        if(depth[next_node.first]>depth[curr_node] and next_node.second>0){
            ll ret=dfs(next_node.first, tar_node, min(flow,next_node.second));
            if(ret!=0){
                adj[curr_node][adj[curr_node].size()-1].second-=ret;
                for(ll j=0;j<adj[next_node.first].size();j++){
                    if(adj[next_node.first][j].first==curr_node){
                        adj[next_node.first][j].second+=ret;
                        break;
                    }
                }
                return ret;
            }else{
                adj[curr_node].pop_back();
            }
        }
    }
    return 0;
}

int main(){
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    for(ll i=0;i<m;i++){
        ll from,to,cap;
        cin>>from>>to>>cap;
        adj[from].push_back({to,cap});
        is_present[from][to]=true;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<adj[i].size();j++){
            if(!is_present[adj[i][j].first][i]){
                adj[adj[i][j].first].push_back({i,0});
            }
        }
    }
    while(true){
        for(ll i=0;i<=n;i++){
            depth[i]=0;
            visited[i]=0;
        }
        bfs(s);
        if(depth[t]==0)
            break;
        while(ll flow=dfs(s,t,1e18)){
            ans+=flow;
        }
    }
    cout<<ans<<endl;
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
2

3 4
3 2
3 1 64
3 2 26
1 3 114
1 2 79
90

61 117
1 61
1 2 2
1 3 2
2 4 2
2 5 2
3 4 2
3 5 2
4 6 2
4 7 2
5 6 2
5 7 2
6 8 2
6 9 2
7 8 2
7 9 2
8 10 2
8 11 2
9 10 2
9 11 2
10 12 2
10 13 2
11 12 2
11 13 2
12 14 2
12 15 2
13 14 2
13 15 2
14 16 2
14 17 2
15 16 2
15 17 2
16 18 2
16 19 2
17 18 2
17 19 2
18 20 2
18 21 2
19 20 2
19 21 2
20 22 2
20 23 2
21 22 2
21 23 2
22 24 2
22 25 2
23 24 2
23 25 2
24 26 2
24 27 2
25 26 2
25 27 2
26 28 2
26 29 2
27 28 2
27 29 2
28 30 2
28 31 2
29 30 2
29 31 2
30 32 2
30 33 2
31 32 2
31 33 2
32 34 2
32 35 2
33 34 2
33 35 2
34 36 2
34 37 2
35 36 2
35 37 2
36 38 2
36 39 2
37 38 2
37 39 2
38 40 2
38 41 2
39 40 2
39 41 2
40 42 2
40 43 2
41 42 2
41 43 2
42 44 2
42 45 2
43 44 2
43 45 2
44 46 2
44 47 2
45 46 2
45 47 2
46 48 2
46 49 2
47 48 2
47 49 2
48 50 2
48 51 2
49 50 2
49 51 2
50 52 2
50 53 2
51 52 2
51 53 2
52 54 2
52 55 2
53 54 2
53 55 2
54 56 2
54 57 2
55 56 2
55 57 2
56 58 2
56 59 2
57 58 2
57 59 2
58 60 2
59 60 2
60 61 1
1
*/
