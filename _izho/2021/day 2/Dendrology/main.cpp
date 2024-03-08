#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;

vector<ll> adj[Size];
ll visited[Size],visited_size=1;
ll p[Size],p_2_i[Size];
bool star=true;

void reset_visited(ll n){
    for(ll i=1;i<=n;i++){
        if(visited[i]==1)
            visited[i]=0;
    }
}

bool dfs(ll curr_node,ll prev_node){
    if(visited[curr_node])return 1;
    for(auto itr:adj[curr_node]){
        if(visited[itr]==1){
            visited[curr_node]=1;
            visited_size++;
            return 1;
        }
        if(itr!=prev_node){
            if(dfs(itr,curr_node)){
                visited[curr_node]=1;
                visited_size++;
                return 1;
            }
        }
    }
    return 0;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
        p_2_i[p[i]]=i;
    }
    for(ll i=1,from,to;i<n;i++){
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
        if(from!=1 and to!=1)
            star=0;
    }
    if(0 and n<=1000){
        ll ans=n;
        for(ll i=1;i<=n;i++){
            visited[p_2_i[i]]=1;
            visited_size=1;
            for(ll j=i+1;j<=n;j++){
                dfs(p_2_i[j],0);
                ans+=visited_size;
            }
            reset_visited(n);
        }
        cout<<ans<<endl;
    }else{
        if(star){
            ll ans=n;
            for(ll i=1;i<=n;i++){
                if(p_2_i[i]==1){
                    ans+=i*(n-i);
                }else{
                    if(p[1]<i){
                        ans+=(p[1])*(n-i);
                        ans+=(i-p[1])*(n-i+1);
                    }else{
                        ans+=i*(n-p[1]+1);
                        ans+=(i+1)*(p[1]-i-1);
                    }
                }
            }
            cout<<ans<<endl;
        }
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
3 0
3 2 1
1 2
1 3


7 0
1 3 2 4 6 5 7
3 1
3 2
4 6
5 6
3 7
6 7

9 0
1 2 3 4 5 6 7 8 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
*/
