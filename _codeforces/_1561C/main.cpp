#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+2;
pair<ll,ll> req[Size];
vector<ll> a[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        a[i].clear();
        req[i].first=0;
        cin>>req[i].second;
        for(ll j=0;j<req[i].second;j++){
            ll tmp; cin>>tmp;
            a[i].push_back(tmp);
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<(ll)a[i].size();j++){
            req[i].first+=max(a[i][j]-req[i].first-j+1,(ll)0);
        }
    }
    sort(req,req+n);
    ll ans=0,gained=0;
    for(ll i=0;i<n;i++){
        ans+=max(req[i].first-ans-gained,(ll)0);
        gained+=req[i].second;
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
/*
111674811
646490893
633627900
*/
