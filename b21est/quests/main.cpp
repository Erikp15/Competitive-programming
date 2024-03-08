#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class action{
public:
    ll x,y,value;
};
const ll Size=501;
ll l1_time[Size],l2_time[Size],l1_exp[Size],l2_exp[Size],dp[2*Size+1][2*Size+1];
vector<action> actions;

void solve(){
    ll n,s1,s2,ans=1e18;
    cin>>n>>s1>>s2;
    for(ll i=0;i<=2*Size;i++){
        for(ll j=0;j<=2*Size;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;
    for(ll i=0;i<n;i++){
        cin>>l1_exp[i]>>l1_time[i]>>l2_exp[i]>>l2_time[i];
    }
    for(ll k=0;k<n;k++){
        for(ll i=2*Size;i>=0;i--){
            for(ll j=2*Size;j>=0;j--){
                if(dp[i][j]!=1e18){
                    if(j<s1){
                        dp[i][j+l1_exp[k]]=min(dp[i][j+l1_exp[k]],dp[i][j]+l1_time[k]);
                    }
                    if(i<s2){
                        dp[i+l2_exp[k]][j]=min(dp[i+l2_exp[k]][j],dp[i][j]+l2_time[k]);
                    }
                }
            }
        }
    }
    for(ll i=0;i<=2*Size;i++){
        for(ll j=0;j<=2*Size;j++){
            if(i>=s1 and i+j>=s1+s2 and dp[j][i]!=1e18){
                cout<<j<<" "<<i<<" "<<dp[j][i]<<"\n";
                ans=min(ans,dp[j][i]);
            }
        }
    }

    if(ans==1e18){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
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
5 10 11
5 10 1 100
7 10 10 100
1 100 4 11
1 100 5 11
2 1000 2 1000
*/
