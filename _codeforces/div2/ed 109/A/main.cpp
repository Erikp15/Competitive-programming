#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll gcd(ll a,ll b){
        if(b==0){
            return a;
        }else{
            return gcd(b,a%b);
        }
    }

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll k;
        cin>>k;
        ll m=gcd(k,100-k);
        cout<<(100-k)/m+k/m<<endl;
    }
    return 0;
}
