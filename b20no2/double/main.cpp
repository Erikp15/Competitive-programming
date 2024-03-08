#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=402;
bool dp[Size][Size];

void solve(){
    int n,w1,w2;
    cin>>n>>w1>>w2;
    dp[0][0]=true;
    for(ll i=0,item;i<n;i++){
        cin>>item;
        for(ll i=w2;i>=0;i--){
            for(ll j=w1;j>=0;j--){
                if(dp[i][j]){
                    dp[i+item][j]=true;
                    dp[i][j+item]=true;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<=w2;i++){
        for(ll j=0;j<=w1;j++){
            if(dp[i][j]){
                ans=max(ans,i+j);
            }
        }
    }
    cout<<ans<<endl;
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
3 10 2
3 4 5

4 21 0
1 1 4 5

5 10 14
4 5 6 7 8

9 13 21
4 4 5 5 4 4 5 5 4
*/
