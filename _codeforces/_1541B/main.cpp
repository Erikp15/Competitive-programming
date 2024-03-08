#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
pair<ll,ll> a[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        for(ll j=i+1;a[i].first*a[j].first<=2*n and j<n;j++){
            if(a[i].first*a[j].first==a[i].second+a[j].second)ans++;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
