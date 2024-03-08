#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1002,m=123456789012345;

ll dp[Size][Size],a[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        dp[0][i]=1;
    }
    for(ll i=1;i<=1000;i++){
        for(ll j=2;j<=n;j++){
            for(ll k=1;k<j;k++){
                if(a[k]+i==a[j]){
                    dp[i][j]=(dp[i][j]+dp[i][k]+dp[0][k])%m;
                }
            }
            ans=(ans+dp[i][j])%m;
        }
    }
    cout<<ans<<endl;
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
