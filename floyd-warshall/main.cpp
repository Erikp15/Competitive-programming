#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll const Size=2e3+1;
    vector<pair<ll,ll>> adj[Size];
    ll dist[Size][Size];


    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                dist[i][j]=1e18;
            }
        }
        for(ll i=0;i<m;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
            dist[a][b]=w;
        }
        for(ll i=1;i<=n;i++){
            dist[i][i]=0;
        }
        for(ll k=1;k<n;k++){
            for(ll i=0;i<=n;i++){
                for(ll j=0;j<=n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    solve();
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<dist[a][b]<<endl;
    }
    return 0;
}
/*
1
7 5
1 2 3
1 3 8
2 3 3
2 4 1
3 5 10
*/
