#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll s,ans=0;
        cin>>s;
        for(ll i=1;i<s;i+=2){
            s-=i;
            ans++;
        }
        cout<<ans+1<<"\n";
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
