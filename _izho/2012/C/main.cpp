#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
ll a[Size],ans[Size];

void solve(){
    ll n,x;
    cin>>n>>x;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        ll so_far=0;
        for(ll j=i;j<n;j++){
            so_far=so_far^a[j];
            if(so_far>=x){
                ans[i]=j-i+1;
            }
        }
    }
    pair<ll,ll> max_el={0,0};
    for(ll i=0;i<n;i++){
        max_el=max(max_el,{ans[i],i+1});
    }
    cout<<max_el.second<<" "<<max_el.first<<endl;
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
