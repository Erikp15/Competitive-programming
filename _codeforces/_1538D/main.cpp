#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll factorize(ll a){
        ll p_count=0,check_to=sqrt(a);
        for(ll i=2;i<=check_to;i++){
            for(;a%i==0;a/=i){
                p_count++;
            }
        }
        if(a>1){
            p_count++;
        }
        return p_count;
    }

    void solve(){
        ll a,b,k;
        cin>>a>>b>>k;
        ll gcd=__gcd(a,b);
        ll a_primes=factorize(a);
        ll b_primes=factorize(b);
        if((a==gcd or b==gcd) and k==1 and !(a==gcd and b==gcd)){
            cout<<"Yes"<<endl;
            return;
        }
        if(k>a_primes+b_primes or k<2){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
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
