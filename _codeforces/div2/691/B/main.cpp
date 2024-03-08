#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1000001;
    ll n,dp[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dp[1]=4;
    ll increase=8;
    for(ll i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=(i/2+1)*(i/2+1);
        }else{
            dp[i]=dp[i-2]+increase;
            increase+=4;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
