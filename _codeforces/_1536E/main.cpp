#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll mod=1e9+7;

    void solve(){
        ll n,m;
        cin>>n>>m;
        ll ans=1;
        bool has=false;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                char a;
                cin>>a;
                if(a=='0'){
                    has=true;
                }else{
                    ans=((ll)2*ans)%mod;
                }
            }
        }
        if(has){
            cout<<ans<<"\n";
        }else{
            cout<<(ans-1)<<"\n";
        }
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
