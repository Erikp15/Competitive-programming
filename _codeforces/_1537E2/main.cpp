#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string a,b;

    void solve(){
        ll n,k;
        cin>>n>>k;
        cin>>a;
        b=a[0];
        for(ll i=1;i<n;i++){
            ll compare=0,mod=i;
            if(a[i]>a[compare]){
                break;
            }
            if(a[i]<a[compare]){
                b+=a[i];
                continue;
            }
            while(i<n and a[i]==a[compare]){
                compare=(compare+1)%mod;
                i++;
            }
            if(i==n){
                break;
            }
            if(a[i]<a[compare]){
                for(ll j=mod;j<=i;j++){
                    b+=a[j];
                }
            }else{
                break;
            }
        }
        while(b.size()<k){
            b+=b;
        }
        while(b.size()>k){
            b.pop_back();
        }
        cout<<b<<"\n";
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
/*
1
3
1 2 3
*/
