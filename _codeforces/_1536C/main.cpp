#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll n;
        cin>>n;
        string a;
        cin>>a;
        map<pair<ll,ll>,ll> r_count;
        ll d_count=0,k_count=0;
        for(ll i=0;i<n;i++){
            if(a[i]=='D'){
                d_count++;
            }else{
                k_count++;
            }
            ll gcd=__gcd(d_count,k_count);
            cout<<++r_count[{d_count/gcd,k_count/gcd}]<<" ";

        }
        cout<<"\n";
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
/*
5
3
DDK
6
DDDDDD
4
DKDK
1
D
9
DKDKDDDDK
1 2 1
1 2 3 4 5 6
1 1 1 2
1
1 1 1 2 1 2 1 1 3

*/
