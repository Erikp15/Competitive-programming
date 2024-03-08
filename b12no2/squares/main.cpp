#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;

const ll Size=2e8+100;

bool ans[Size];

void solve(){
    ll n,a=0;
    cin>>n;
    for(ll i=1;i*i<=n;i++){
        for(ll j=0;i*i+j*j<=n and j<=i;j++){
            ans[i*i+j*j]=true;
        }
    }
    for(ll i=0;i<=n;i++){
        a+=ans[i];
    }
    cout<<a<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

