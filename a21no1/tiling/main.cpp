#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e6+10,m=1e9+7;

ll dp[Size][3];

void solve(){
    ll n,t;
    cin>>n>>t;
    dp[0][2]=1;
    dp[1][2]=1;
    if(t==2){
        if(n%3!=0){
            cout<<0<<endl;
            return;
        }
    }
    for(ll i=2;i<=n;i++){
        if(t!=2){
            dp[i][0]=(dp[i][0]+dp[i-1][1])%m;
            dp[i][1]=(dp[i][1]+dp[i-1][0])%m;
            dp[i][2]=(dp[i][2]+dp[i-1][2]+dp[i-2][2])%m;
        }
        if(t!=1){
            dp[i][0]=(dp[i][0]+dp[i-2][2])%m;
            dp[i][1]=(dp[i][1]+dp[i-2][2])%m;
            dp[i][2]=(dp[i][2]+dp[i-1][0]+dp[i-1][1])%m;
        }
    }
    cout<<dp[n][2]<<endl;
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
