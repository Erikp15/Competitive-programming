#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=31;
unsigned ll sol_count[Size][Size];
char a[Size][Size];

void bfs(ll k){
    queue<pair<ll,ll>> to_process
    set<ll> add;
    to_process.push({0,0});
    while(true){
        while(!to_process.empty()){
            pair<ll,ll> curr
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    sol_count[n-1][m-1]=1;
    for(ll i=n-1;i>=0;i--){
        for(ll j=m-1;j>=0;j--){
            if(j!=m-1 and i!=n-1){
                if(1e18-sol_count[i+1][j]<sol_count[i][j+1]){
                    sol_count[i][j]=-1;
                }else{
                    sol_count[i][j]=sol_count[i+1][j]+sol_count[i][j+1];
                }
            }
        }
    }
    ll k;
    cin>k;
    bfs(k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
