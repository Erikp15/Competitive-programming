#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=2e3;

ld dp[Size];

void solve(){
    for(ll i=1;i<=1000;i++)dp[i]=-1;
    ll n,m;
    cin>>n>>m;
    for(ll i=0,weight;i<n;i++){
        ld value;
        cin>>weight>>value;
        for(ll j=m;j>=0;j--){
            if(dp[j]!=-1){
                dp[j+weight]=max(dp[j+weight],dp[j]+value);
            }
        }
    }
    cout<<fixed<<setprecision(2)<<*max_element(dp,dp+m+1)<<endl;
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
/*
5 8
6 32.00
8 48.00
3 13.40
1 15.10
4 21.20
*/
