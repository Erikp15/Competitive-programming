#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=300;

ll dp[Size][Size];

void solve(){
    ll n,m;
    cin>>n>>m;
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            for(ll k=1;k<=j;k++){
                dp[i][j]+=dp[i-k][min(i-k,k)];
            }
        }
        for(ll j=i+1;j<=m;j++){
            dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
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
