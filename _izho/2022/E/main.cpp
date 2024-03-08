#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;

vector<ll> adj[Size];
ll dist_a[Size],dist_b1[Size],dist_b2[Size],degree[Size];
ll dist[4001][4001];
queue<ll> to_process;
bool visited[Size];

void dfs1(ll curr_node,ll depth,ll is_a){
    if(is_a==1){
        dist_a[curr_node]=depth;
    }
    if(is_a==2){
        dist_b1[curr_node]=depth;
    }
    if(is_a==3){
        dist_b2[curr_node]=depth;
    }
    visited[curr_node]=1;
    for(auto itr:adj[curr_node]){
        if(!visited[itr]){
            dfs1(itr,depth+1,is_a);
        }
    }
}

void dfs2(ll start_node,ll curr_node,ll depth){
    dist[start_node][curr_node]=min(dist[start_node][curr_node],depth);
    visited[curr_node]=1;
    for(auto itr:adj[curr_node]){
        if(!visited[itr]){
            dfs2(start_node,itr,depth+1);
        }
    }
}

void reset(ll n){
    for(ll i=1;i<=n;i++){
        adj[i].clear();
        dist_a[i]=0;
        dist_b1[i]=0;
        dist_b2[i]=0;
        visited[i]=0;
        degree[i]=0;
    }
    while(!to_process.empty())
        to_process.pop();
}

void reset_visited(ll n){
    for(ll i=1;i<=n;i++)
        visited[i]=0;
}

void solve(){
    ll n,p;
    cin>>n>>p;
    reset(n);
    for(ll i=0,from,to;i<n-1;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
        degree[from]++;
        degree[to]++;
    }
    if(p==1){
        reset_visited(n);
        for(ll i=1;i<=n;i++){
            dfs2(i,i,0);
            reset_visited(n);
        }
        ll best_ans=1e18;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                ll ans=0;
                for(ll k=1;k<=n;k++){
                    ans+=min(dist[i][k],dist[j][k]);
                }
                best_ans=min(ans,best_ans);
            }
        }
        cout<<best_ans<<endl;
    }
    if(p==2){
        for(ll i=1;i<=n;i++){
            dfs2(i,i,0);
            reset_visited(n);
        }
        ll best_ans=1e18;
            ll ans=0;
            for(ll j=1;j<=n;j++){
                ans+=min(dist[1][j];
            }
            best_ans=min(ans,best_ans);
        /*
        if(n==1 or n==2){
            cout<<0<<endl;
            return;
        }
        dfs1(1,0,1);
        reset_visited(n);
        visited[1]=1;
        for(auto itr:adj[1]){
            degree[itr]--;
        }
        ll final_amount=0;
        for(ll i=1;i<=n;i++){
            if(degree[i]==0)final_amount++;
            if(degree[i]==1 and !visited[i]){
                to_process.push(i);
                visited[i]=1;
            }
        }
        ll processed=0;
        while(!to_process.empty()){
            ll curr_node=to_process.front();
            visited[curr_node]=1;
            processed++;
            if(processed==n-2-final_amount)break;
            to_process.pop();
            for(auto itr:adj[curr_node]){
                degree[itr]--;
                if(!visited[itr] and degree[itr]==1){
                    to_process.push(itr);
                }
            }
        }
        reset_visited(n);
        if(to_process.empty()){
            cout<<n-2<<endl;
            return;
        }
        ll mid=to_process.front();
        dfs1(mid,0,2);
        to_process.pop();
        reset_visited(n);
        mid=to_process.front();
        dfs1(mid,0,3);
        ll ans=0,best_ans=1e18;
        for(ll i=1;i<=n;i++){
            ans+=min(dist_a[i],dist_b1[i]);
        }
        best_ans=min(ans,best_ans);
        ans=0;
        for(ll i=1;i<=n;i++){
            ans+=min(dist_a[i],dist_b2[i]);
        }
        best_ans=min(ans,best_ans);
        cout<<best_ans<<endl;
        */
    }
    if(p==3){
        reset_visited(n);
        for(ll i=1;i<=n;i++){
            dfs2(i,i,0);
            reset_visited(n);
        }
        for(ll i=1;i<=n;i++){
            ll best_ans=1e18;
            for(ll j=1;j<=n;j++){
                ll ans=0;
                for(ll k=1;k<=n;k++){
                    ans+=min(dist[i][k],dist[j][k]);
                }
                best_ans=min(best_ans,ans);
            }
            cout<<best_ans<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
10
7 2
1 2
2 3
3 4
3 5
2 6
1 7
5 2
1 2
2 3
3 4
4 5
5 2
1 5
1 2
1 3
1 4
11 2
1 2
2 4
6 10
7 9
2 5
6 11
3 6
1 3
7 8
3 7
20 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
18 19
19 20
17 18
7 2
1 2
2 4
6 7
2 3
2 5
5 6
6

5 2
1 2
2 3
3 4
4 5
3

1
5 2
1 5
1 2
1 3
1 4
3

1
11 2
1 2
2 4
6 10
7 9
2 5
6 11
3 6
1 3
7 8
3 7


1
7 2
1 2
2 4
6 7
2 3
2 5
5 6

7

1
20 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
18 19
19 20
17 18

*/
