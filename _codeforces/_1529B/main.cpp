#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+2;
ll a[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,m=1e18,index=0;
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        if(a[i]<=0){
            ans++;
        }
        if(a[i]>0){
            m=a[i];
            index=i;
            break;
        }
    }
    if(m==1e18){
        cout<<ans<<"\n";
        return;
    }
    for(ll i=1;i<index;i++){
        if(abs(a[i]-a[i-1])<m){
            cout<<ans<<"\n";
            return;
        }
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
/*
111674811
646644446
*/
