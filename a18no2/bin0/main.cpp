#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=70;

ll dp[Size][Size];

void solve(){
    ll s,t,z;
    cin>>s>>t>>z;
    if(false){
        ll ans=0;
        for(ll i=s;i<=t;i++){
            ll bits=64-__builtin_clzll(i)-__builtin_popcountll(i);
            if(bits==z)
                ans++;
        }
        cout<<ans<<endl;
    }else{
        for(ll i=1;i<=64;i++){
            dp[0][i]=dp[0][i-1]*2;
        }
        dp[1][0]=1;
        dp[1][1]=1;
        for(ll i=1;i<=64;i++){
            dp[i][i+1]=1+dp[i][i];
            dp[i][i+2]=dp[i][i+1]+z+1;
            for(ll j=i+3;j<=64;j++){
                dp[i][j]=dp[i][j-1]*2;
            }
        }
        if(z==__builtin_ctz(t)){
            cout<<1<<endl;
            return;
        }
        cout<<dp[z][__builtin_ctz(t)]-dp[z][__builtin_ctz(s)]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
