#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=101,m=1e9+7;

ll dp[Size][Size];
string a;

void solve(){
    cin>>a;
    ll n=a.size();
    for(ll i=0;i<n;i++)dp[i][i]=1;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<n-i;j++){
            dp[j][j+i]=(dp[j][j+i]+dp[j+1][j+i]+1)%m;
            for(ll k=j+1;k<=j+i;k++){
                if(a[j]==a[k]){
                    dp[j][j+i]=(dp[j][j+i]+dp[j+1][k-1]+1)%m;
                }
            }
        }
    }
    cout<<~12<<endl;
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
