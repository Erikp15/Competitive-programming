#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1;
    ll a[Size];

    void solve(){
        ll n,ans;
        cin>>n;
        ans=2*n-1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=2;i<n;i++){
            if(!(a[i]>=a[i-1] and a[i-1]>=a[i-2]) and !(a[i]<=a[i-1] and a[i-1]<=a[i-2])){
                ans++;
            }
        }
        for(ll i=3;i<n;i++){
            if(!(a[i]>=a[i-1] and a[i-1]>=a[i-2]) and !(a[i]<=a[i-1] and a[i-1]<=a[i-2])){
                if(!(a[i-1]>=a[i-2] and a[i-2]>=a[i-3]) and !(a[i-1]<=a[i-2] and a[i-2]<=a[i-3])){
                    if(!(a[i]>=a[i-2] and a[i-2]>=a[i-3]) and !(a[i]<=a[i-2] and a[i-2]<=a[i-3])){
                        if(!(a[i]>=a[i-1] and a[i-1]>=a[i-3]) and !(a[i]<=a[i-1] and a[i-1]<=a[i-3])){
                            ans++;
                        }
                    }
                }
            }
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
