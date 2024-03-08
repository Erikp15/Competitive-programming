#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll find_count(ll n){
        ll ans=0;
        for(ll i=0;i<10;i++){
            ans+=n/pow(10,i);
        }
        return ans;
    }

    void solve(){
        ll l,r;
        cin>>l>>r;
        cout<<find_count(r)-find_count(l)<<"\n";
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
