#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll pre[Size],num[Size];

void solve(){
    ll n,q;
    cin>>n>>q;
    string a;
    cin>>a;
    for(ll i=0;i<n;i++){
        a[i]=='+' ? num[i]=1 : num[i]=-1;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--; r--;
        if(l==0){
            cout<<abs(pre[r])<<"\n";
            continue;
        }
        cout<<abs(pre[r]-pre[l-1])<<"\n";
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
