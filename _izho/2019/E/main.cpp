#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll Size=3e3+1;
ll a[Size];
pair<ll,ll> dp[Size][Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            dp[i][j].first=-1;
            dp[i][j].second=-1;
        }
    }
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0][1].second=a[0];
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=i+1;j++){
            if(dp[i-1][j-1].first<=dp[i-1][j-1].second and dp[i-1][j-1].second!=-1){
                dp[i][j].first=dp[i-1][j-1].second;
                dp[i][j].second=a[i];
            }
            if(dp[i-1][j].second!=-1){
                if(dp[i-1][j].first-dp[i-1][j].second+a[i]>dp[i][j].first-dp[i][j].second or dp[i][j].second==-1){
                    dp[i][j].first=dp[i-1][j].first;
                    dp[i][j].second=dp[i-1][j].second+a[i];
                }
            }
        }
    }
    for(ll i=n;i>=0;i--){
        if(dp[n-1][i].second!=-1 and dp[n-1][i].second>=dp[n-1][i].first){
            cout<<i<<endl;
            return;
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
