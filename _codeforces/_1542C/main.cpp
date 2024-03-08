#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll mod=1e9+7;

    ll lcm(ll a,ll b){
        return a/__gcd(a,b)*b;
    }

    void solve(){
        ll n;
        cin>>n;
        ll lcm_so_far=1;
        ll ans=0;
        for(ll i=1;lcm_so_far<=n;i++){
            lcm_so_far=lcm(i,lcm_so_far);
            if(lcm_so_far>n)break;
            ans=(ans+n/lcm_so_far);
        }
        cout<<(ans+n)%mod<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
