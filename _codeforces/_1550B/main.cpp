#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll n,a,b;
        cin>>n>>a>>b;
        string m;
        cin>>m;
        ll count_1=0,count_0=0;
        for(ll i=1;i<n;i++){
            if(m[i]=='1' and m[i-1]=='0')count_0++;
            if(m[i]=='0' and m[i-1]=='1')count_1++;
        }
        if(m[n-1]=='0'){
            count_0++;
        }else{
            count_1++;
        }
        ll ans=-999999999;
        for(ll i=(min(count_1,count_0)+1);i<=n;i++){
            ans=max(ans,a*n+b*i);
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
