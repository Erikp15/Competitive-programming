#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e7+1,mod=1e9+7;

void solve(){
    ll n,m;
    cin>>n>>m;
    ll gcd=__gcd(n,m);
    n/=gcd;
    m/=gcd;
    if(m>n){
        //cout<<n<<" "<<m<<" "<<"NO"<<"\n";
        cout<<"NO"<<"\n";
        return;
    }
    ll pow_3=1;
    for(ll i=0;i<50;i++){
        if(pow_3>n){
            //cout<<n<<" "<<m<<" "<<"NO"<<"\n";
            cout<<"NO"<<"\n";
            return;
        }
        ll total_pow_3=pow_3;
        ll pow_2=1;
        for(ll j=0;j<50;j++){
            if(pow_3>n){
                break;
            }
            if(pow_2==m and total_pow_3==n){
                //cout<<n<<" "<<m<<" "<<"YES"<<"\n";
                cout<<"YES"<<"\n";
                return;
            }
            pow_2*=2;
            total_pow_3*=3;
        }
        pow_3*=3;
    }
    cout<<"NO"<<"\n";
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
