#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll c1=n/3,c2=n/3;
    if(n%3==0){
        cout<<c1<<" "<<c2<<"\n";
    }
    if(n%3==1){
        cout<<c1+1<<" "<<c2<<"\n";
    }
    if(n%3==2){
        cout<<c1<<" "<<c2+1<<"\n";
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
