#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll ans[Size];

void solve(){
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    for(ll i=n-1;i>=1;i--){
        ans[i]=sum+1;
        sum=(sum+ans[i])%m;
    }
    cout<<ans[1]<<"\n";
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

111674811
646490893
633627900
*/
