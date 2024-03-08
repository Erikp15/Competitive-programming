#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3e5+1,m=1e9+7;

    void solve(){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a.begin(),a.end());
        ll ans=1;
        for(ll i=1;i<n;i++){
            if(a[i-1].second+1!=a[i].second)ans++;
        }
        if(ans<=k){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
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
3
5 4
6 3 4 2 1
4 2
1 -4 0 -2
5 1
1 2 3 4 5

*/
