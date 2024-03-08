#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class matrix{
public:
    ll x,y;
};

const ll Size=101;
ll n,a[Size],dp[Size][Size];
matrix matrices[Size];

void solve(){
    cin>>n;
    for(ll i=0;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        matrices[i].x=a[i];
        matrices[i].y=a[i+1];
        dp[i][i]=0;
    }
    for(ll i=1;i<n;i++){
        for(ll j=0;j+i<n;j++){
            dp[j][j+i]=1e18;
            for(ll k=j;k<=j+i;k++){
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+matrices[j].x*matrices[k].y*matrices[j+i].y);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
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
