#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
typedef long long ll;

    const ll MOD=1e9+7;

    ll norm(ll a) {
        while (a >= MOD)
            a -= MOD;
        while (a < 0)
            a += MOD;
        return a;
    }
    ll mul(ll a, ll b) {
        return ll(a * 1ll * b % MOD);
    }
    ll binPow(ll a, ll k) {
        ll ans = 1;
        while (k > 0) {
            if (k & 1)
                ans = mul(ans, a);
            a = mul(a, a);
            k >>= 1;
        }
        return ans;
    }

    const ll N = 200 * 1000 + 55;
    ll f[N], inf[N];

    void precalc() {
        f[0] = inf[0] = 1;
        fore (i, 1, N) {
            f[i] = mul(f[i - 1], i);
            inf[i] = binPow(f[i], MOD - 2);
        }
    }

    void solve(){
        ll n,l,r,ans=0;
        cin>>n>>l>>r;
        ll lf=n/2;
        ans+=f[n]*inf[lf]%MOD*inf[lf]%MOD;
        if(n%2==1){
            ans+=f[n]*inf[lf+1]%MOD*inf[n-lf-1]%MOD;
            for(ll k=min(1-l,r-n)+1;n<k;k++){
                ll lg=max((ll)1,l+k),rg=min(n,r-k);
                ans+=f[rg-lg+1]*inf[lf-(lg-1)]%MOD*inf[n-(lf-(lg-1))]%MOD;
                ans+=f[rg-lg+1]*inf[lf+1-(lg-1)]%MOD*inf[n-(lf+1-(lg-1))]%MOD;
            }
        }else{
            for(ll k=min(1-l,r-n)+1;n<k;k++){
                ll lg=max((ll)1,l+k),rg=min(n,r-k);
                ans+=f[rg-lg+1]*inf[lf-(lg-1)]%MOD*inf[n-(lf-(lg-1))]%MOD;
            }
        }
        cout<<ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tests;
    cin>>tests;
	precalc();
    while(tests--){
        solve();
    }
    return 0;
}
