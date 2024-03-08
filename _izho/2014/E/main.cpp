#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
ll a[Size];

void solve(){
    ll n,k,ans=0;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    cout<<ans<<"\n";
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
