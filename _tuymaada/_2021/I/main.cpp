#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=1e3+1,mod=998244353;
    ll turns=0,startx=0,starty=0,endx=0,endy=0;
    char g[Size][Size],startd='U';
    vector<ll> adj[Size*Size];

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>g[i][j];
                if(j<m-1){
                    adj[g[i][j]].push_back(g[i][j+1]);
                }
                if(j>0){
                    adj[g[i][j]].push_back(g[i][j-1]);
                }
                if(i<n-1){
                    adj[g[i][j]].push_back(g[i+1][j]);
                }
                if(i>0){
                    adj[g[i][j]].push_back(g[i-1][j]);
                }
                if(g[i][j]!='.' and g[i][j]!='*' and g[i][j]!='E'){
                    startx=i;
                    starty=j;
                    startd=g[i][j];
                }
                if(g[i][j]=='E'){
                    endx=i;
                    endy=j;
                }
            }
        }

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
