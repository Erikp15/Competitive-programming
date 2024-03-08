#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=1e3+1,mod=998244353;
    ll dp[Size][Size];

    void solve(){
        ll n,m,l;
        cin>>n>>m>>l;
        l++;
        dp[1][1]=1;
        for(ll i=2;i<=n;i++){
            dp[i][1]=i/l;
        }
        for(ll i=2;i<=m;i++){
            dp[1][i]=i/l;
        }
        for(ll i=2;i<=n;i++){
            for(ll j=2;j<=m;j++){
                dp[i][j]=max(dp[i-1][j]+dp[1][j],dp[i][j-1]+dp[i][1]);
            }
        }
        cout<<dp[n][m]<<"\n";
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
