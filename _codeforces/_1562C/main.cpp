#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll ans[Size];

void solve(){
    ll n; cin>>n;
    string a;
    cin>>a;
    ll c=0,l1,r1,l2,r2;
    for(ll i=n/2;i<n;i++){
        bool valid=false;
        for(ll j=i-n/2;j<i;j++){
            if(a[i]=='1'){
                valid=true;
                break;
            }
        }
        if(valid){
            cout<<i-n/2+1<<" "<<i+1<<" "<<i-n/2+1<<" "<<i<<"\n";
            return;
        }
        valid=false;
        for(ll j=i-n/2+1;j<=i;j++){
            if(a[i]=='1'){
                valid=true;
                break;
            }
        }
        if(valid){
            cout<<i-n/2+1<<" "<<i+1<<" "<<i-n/2+2<<" "<<i+1<<"\n";
            return;
        }
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
