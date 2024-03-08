#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1,m=1e9+7;
    ll a[Size];

    void solve(){
        ll n,s1=0;
        cin>>n;
        pair<ll,ll> max_a={-1e18,-1e18};
        for(ll i=0;i<n;i++){
            cin>>a[i];
            max_a=max(max_a,{a[i],i});
        }
        for(ll i=0;i<n;i++){
            if(i!=max_a.second)s1+=a[i];
        }
        cout<<fixed<<setprecision(6)<<(double(s1)/double(n-1))+double(max_a.first)<<"\n";
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

*/
