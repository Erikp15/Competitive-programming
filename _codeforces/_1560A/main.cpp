#include <iostream>

using namespace std;

typedef long long ll;

const ll Size=4e5+2;

void solve(){
    ll n,a=0;
    cin>>n;
    for(ll i=1;;i++){
        if(i%3!=0 and i%10!=3){
            a++;
        }
        if(a==n){
            cout<<i<<"\n";
            return;
        }
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
