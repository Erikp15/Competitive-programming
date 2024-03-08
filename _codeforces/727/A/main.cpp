#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll n,x,t;
        cin>>n>>x>>t;
        ll num=min(t/x,n);
        if(t<x){
            cout<<0<<"\n";
            return;
        }
        ll ans=n*(n-1)/2;
        cout<<ans-((n-num-1)*(n-num)/2)<<"\n";
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
