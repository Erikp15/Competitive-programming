#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2001;
    ll n,a[Size],dp[Size][Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=a[0];
    for(ll i=1;i<n;i++){
        for(ll j=0;j<=i;j++){
            if(j!=0){
                dp[i][j]=max(dp[i-1][j-1]+a[i],dp[i-1][j]);\
            }

        }
    }
    for(ll i=n-1;i>=0;i--){
        if(dp[n-1][i]>=0){cout<<i+1<<endl; return 0;}
    }
    return 0;
}
