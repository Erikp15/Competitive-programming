#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll dp[Size][2];

void solve(){
    string a;
    cin>>a;
    dp[0][0]=0;
    dp[0][1]=0;
    ll ans=0;
    for(ll i=1;i<=a.size();i++){
        if(a[i-1]=='0'){
            dp[i][0]=dp[i-1][1]+1;
            dp[i][1]=0;
        }
        if(a[i-1]=='1'){
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=0;
        }
        if(a[i-1]=='?'){
            dp[i][0]=dp[i-1][1]+1;
            dp[i][1]=dp[i-1][0]+1;
        }
        ans+=max(dp[i][0],dp[i][1]);
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
