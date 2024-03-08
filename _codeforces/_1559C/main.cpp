#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e4+1;
bool a[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        if(!a[i-1] and a[i]){
            for(ll j=0;j<i;j++){
                cout<<j+1<<" ";
            }
            cout<<n+1<<" ";
            for(ll j=i;j<n;j++){
                cout<<j+1<<" ";
            }
            cout<<"\n";
            return;
        }
    }
    if(a[0]){
        cout<<n+1<<" ";
        for(ll i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }else{
        for(ll i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<n+1<<"\n";
        return;
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
