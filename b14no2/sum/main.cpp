#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;
ll a[Size],pre[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    ll min_pre=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        min_pre=min(min_pre,pre[i]);
        ans=max(ans,pre[i]-min_pre);
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
