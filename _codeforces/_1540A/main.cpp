#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const Size=1e5+1;

ll a[Size],pre[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ans+=a[n-1];
    for(ll i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(ll i=0;i<n;i++){
        ans-=(i+1)*a[i]-pre[i];
    }
    cout<<ans<<"\n";
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
1
5
0 1 2 3 4
*/
