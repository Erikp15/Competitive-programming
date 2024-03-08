#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=1e5+1,mod=998244353;

    void solve(){
        ll n,ans=0;
        cin>>n;
        string a;
        for(ll i=0;i<2*n;i++){
            a+='0';
        }
        for(;true;){
            ll count_1=0;
            bool is_v=true;
            for(ll j=0;j<2*n;j++){
                ll half; (j+1)%2==0 ? half=(j+1)/2 : half=(j+1)/2+1;
                if(a[j]=='1')count_1++;
                if(count_1<half)is_v=false;
            }
            if(is_v)ans++;
            ll j=0;
            for(;a[j]=='1';j++){
                if(j==2*n-1){
                    cout<<ans<<"\n";
                    return;
                }
                a[j]='0';
            }
            a[j]='1';
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
