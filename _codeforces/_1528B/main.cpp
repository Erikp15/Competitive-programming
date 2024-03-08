#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1000001,m=998244353;
    ll dp[Size];

    all_divisors(ll n){
        ll ans=0;
        for(ll i=1;i<=n/2;i++){
            if(n%i==0){
                ans++;
            }
        }
        return ans+1;
    }

    void solve(){
        ll n;
        cin>>n;
        dp[0]=1;
        dp[1]=1;
        ll sum_so_far=1;
        for(ll i=2;i<=n;i++){
            dp[i]=(dp[i]+sum_so_far)%m;
            sum_so_far=(sum_so_far+dp[i])%m;
        }
        cout<<dp[n]<<"\n";
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
