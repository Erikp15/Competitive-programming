#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e3+2,mod=1e9+7;
ll grid[Size][Size];
bool visited[Size][Size];

ll dfs(ll i,ll j){
    visited[i][j]=1;
    ll curr=grid[i][j];
    if(grid[i][j+1]!=0 and !visited[i][j+1]){
        ll res=dfs(i,j+1);
        curr+=res;
    }
    if(grid[i][j-1]!=0 and !visited[i][j-1]){
        ll res=dfs(i,j-1);
        curr+=res;
    }
    if(grid[i+1][j]!=0 and !visited[i+1][j]){
        ll res=dfs(i+1,j);
        curr+=res;
    }
    if(grid[i-1][j]!=0 and !visited[i-1][j]){
        ll res=dfs(i-1,j);
        curr+=res;
    }
    return curr;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>grid[i][j];
            visited[i][j]=0;
        }
    }
    ll best=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(!visited[i][j] and grid[i][j]){
                ll ans=dfs(i,j);
                best=max(ans,best);
            }
        }
    }
    cout<<best<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
