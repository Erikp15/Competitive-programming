#include <iostream>

using namespace std;

typedef long long ll;

const ll Size=4e5+2;
ll a[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=0;
    for(ll i=1;i<=n;i++){
        ll l=min(a[i],max(a[i-1],a[i+1]));
        ans+=a[i]-l+abs(l-a[i-1]);
        a[i]=l;
    }
    cout<<a[n]+ans<<"\n";
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
