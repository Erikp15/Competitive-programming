#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void o(ll n){
    for(ll i=1;i<2*n;i++){
        for(ll j=1;j<=n-abs(n-i);j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ll n;
    cin>>n;
    o(n);
    return 0;
}
