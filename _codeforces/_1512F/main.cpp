#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    ll a[Size],b[Size],dp[Size],leftover[Size];

    void solve(){
        ll n,c;
        cin>>n>>c;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            dp[i]=0;
            leftover[i]=0;
        }
        for(ll i=0;i<n-1;i++){
            cin>>b[i];
        }

        for(ll i=1;i<n;i++){
            ll days_to_up;
            b[i-1]-=leftover[i-1];
            if(b[i-1]<0){
                b[i-1]+=leftover[i-1];
                leftover[i]=leftover[i-1]-b[i];
                dp[i]=dp[i-1]+1;
                continue;
            }
            b[i-1]%a[i-1]==0 ? days_to_up=b[i-1]/a[i-1] : days_to_up=b[i-1]/a[i-1]+1;
            leftover[i]=days_to_up*a[i-1]-b[i-1];
            b[i-1]+=leftover[i-1];
            dp[i]=dp[i-1]+days_to_up+1;
        }
        ll ans=10e10;
        for(ll i=0;i<n;i++){
            ll days_to_c;
            (c-leftover[i])%a[i]==0 ? days_to_c=(c-leftover[i])/a[i] : days_to_c=(c-leftover[i])/a[i]+1;
            ans=min(ans,dp[i]+days_to_c);
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
/*
1
4 15
1 3 10 11
1 2 7
6

1
5 15
1 3 7 8 15
2 1 4 13
7

1
3 10
2 3 10
1 1
4

1
3 10
2 3 5
1 1
5
*/
