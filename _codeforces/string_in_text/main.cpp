#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1,m=1e9+7;
    ll prefix[Size];


    ll hashing(string& a){
        ll p=31;
        ll p_pow=1;
        ll hash_value=0;
        for(ll i=0;i<a.size();i++){
            hash_value=(hash_value+(a[i]-'a'+1)*p_pow)%m;
            p_pow=(p_pow*p)%m;
        }
        return hash_value;
    }


    void solve(){
        string a,b,t;
        cin>>a>>b;
        ll p=31,p_pow=1;
        prefix[0]=0;
        for(ll i=1;i<=a.size();i++){
            prefix[i]=(prefix[i-1]+(a[i]-'a'+1)*p_pow)%m;
            p_pow=(p_pow*p)%m;
        }
        ll value=hashing(b);
        for(ll i=0;i<=a.size()-b.size();i++){
            ll curr_hash=(prefix[i+b.size()]+m-prefix[i])%m;
            if(curr_hash==value){
                cout<<"Yes"<<endl;
                return;
            }
            value=(value*p)%m;
        }
        cout<<"No"<<endl;
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
/*
10
alabalaxalabala
bla
abla
xalab
aa
labal

1
aaaaaadaaaaac
aaaad

1
aaaabbaaaa
aaabbaaa
*/
