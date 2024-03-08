#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e3+10;

ll dp[Size][Size];

void solve(){
    ll n,k;
    cin>>n>>k;
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<i;j++){
            dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
        }
        dp[i][i]=1;
    }
    cout<<dp[n][k]<<endl;
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
