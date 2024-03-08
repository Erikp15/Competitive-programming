#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e5+1;
ll a[Size],pre[Size];
unordered_map<ll,ll> rad;

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
        ans+=rad[pre[i]];
        if(pre[i]==0)ans++;
        rad[pre[i]]++;
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
