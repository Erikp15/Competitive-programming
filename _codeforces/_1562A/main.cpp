#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll ans[Size];

void solve(){
    ll l,r;
    cin>>l>>r;
    if(r==l){
        cout<<0<<"\n";
        return;
    }
    cout<<r%(max(r/2+1,l))<<"\n";
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
