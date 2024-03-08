#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=400001,m=1e9+7;
    ll a[Size],b[Size],chain_count=0;


    void solve(){
        ll n;
        cin>>n;
        ll k=n/2;
        ll i=0;
        if(n==1){
            cout<<'a'<<"\n";
            return;
        }
        for(;i<k;i++){
            cout<<'a';
        }
        if(n%2==0){
            cout<<"b";
        }else{
            cout<<"bc";
        }
        for(ll i=0;i<k-1;i++){
            cout<<'a';
        }
        cout<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 4 5
5 4 2 3 1

*/
