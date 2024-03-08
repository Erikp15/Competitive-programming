#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e5+1;
    ll a[3][Size],pre_sum[Size],suffix[Size],ans[Size];

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++){
            pre_sum[i]=0;
            suffix[i]=0;
        }
        for(ll i=0;i<2;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(ll i=0;i<n-1;i++){
            pre_sum[i]=pre_sum[i-1]+a[1][i];
        }
        for(ll i=n-1;i>0;i--){
            suffix[i]=suffix[i+1]+a[0][i];
        }
        ll best=1e18;
        for(ll i=0;i<n;i++){
            best=min(best,max(pre_sum[i-1],suffix[i+1]));
        }
        cout<<best<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
