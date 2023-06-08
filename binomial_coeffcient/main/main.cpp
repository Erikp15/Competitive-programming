#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m=1e9+7;

ll power(ll a,ll b){
    ll bit=1,val=a,ans=1;
    while(bit<=b){
        if(bit&b)
            ans=(ans*val)%m;
        val=(val*val)%m;
        bit<<=1;
    }
    return ans;
}

ll fact(ll n){
    ll val=1;
    for(ll i=2;i<=n;i++){
        val=(val*i)%m;
    }
    return val;
}

ll comb(ll n,ll k){
    ll a=fact(n);
    ll b=power(fact(k),m-2);
    ll c=power(fact(n-k),m-2);
    return (a*b)%m*c%m;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<comb(a,b)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=10;
    while(t--){
        solve();
    }
    return 0;
}
