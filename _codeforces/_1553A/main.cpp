#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1;

    void solve(){
        ll n;
        cin>>n;
        ll ans=n/10;
        if(n%10==9){
            ans++;
        }
        cout<<ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9
*/
