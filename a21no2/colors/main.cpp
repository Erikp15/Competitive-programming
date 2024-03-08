#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e5+10,m=1e9+7;

ll a[Size],dp[2][Size];

void solve(){
    ll n,k,ans=1;
    cin>>n>>k;
    ll f=0,l=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0 and !f)f=i;
        if(a[i]>0)l=i;
    }
    if(!f){
        ans=k;
        for(ll i=0;i<n-1;i++){
            ans=(ans*(k-1))%m;
        }
        cout<<ans<<endl;
        return;
    }
    dp[1][0]=1;
    dp[0][1]=k-1;
    dp[1][1]=k-2;
    for(ll i=2;i<=n;i++){
        dp[0][i]=(dp[0][i-2]*(k-1))%m+(dp[0][i-1]*(k-2))%m;
        dp[1][i]=(dp[1][i-2]*(k-1))%m+(dp[1][i-1]*(k-2))%m;
    }
    for(ll i=f+1,c=0,p=a[f];i<=l;i++){
        if(a[i]==0){
            c++;
        }else{
            if(a[i]==p){
                ans=(ans*dp[0][c])%m;
            }else{
                ans=(ans*dp[1][c])%m;
            }
            c=0;
            p=a[i];
        }
    }
    ll s=1;
    for(ll i=1;a[i]==0;i++){
        s=(s*(k-1))%m;
    }
    ans=(ans*s)%m;
    ll e=1;
    for(ll i=n;a[i]==0;i--){
        e=(e*(k-1))%m;
    }
    ans=(ans*e)%m;
    cout<<ans<<endl;
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
/*
4 3
2 0 1 0

3 5
4 0 4

6 4
0 1 3 0 0 1
*/
