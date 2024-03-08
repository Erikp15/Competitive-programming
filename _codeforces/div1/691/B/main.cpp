#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,w[101],c[101],dp[101],max_c[101],max_w[101],total_water=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>c[i]>>w[i];
        total_water+=w[i];
        max_c[i]=c[i];
        max_w[i]=w[i];
    }
    sort(max_c,max_c+n,greater<ll>());
    sort(max_w,max_w+n,greater<ll>());
    for(ll i=1;i<=n;i++){
        dp[i]=dp[i-1]+min(max_c[i]/2,total_water);
        total_water=max(total_water-max_c[i],(ll)0);
    }
    for(ll i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
/*
3
6 5
6 5
10 2

*/
