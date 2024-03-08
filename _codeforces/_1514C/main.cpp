#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    bool is_coprime[100001];

    void solve(){
        ll n;
        cin>>n;
        ll p=1;
        for(ll i=1;i<n;i++){
            if(__gcd(i,n)==1){
                is_coprime[i]=true;
                p=(p*i)%n;
            }
        }
        if(p!=1){
            is_coprime[p]=false;
        }
        cout<<count(is_coprime+1,is_coprime+n,1)<<"\n";
        for(ll i=1;i<n;i++){
            if(is_coprime[i]){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
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
