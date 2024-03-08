#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=2e5+1,block=450;
ll n;
ll a[Size];
bool is_present[Size];
set<ll> curr_list;
ll target[block][1000];

void solve(){
    cin>>n;
    for(ll i=0;i<block;i++){
        for(ll j=0;j<1000;j++){

        }
    }
    for(ll i=1;i<=n;i++){
        is_present[i]=false;
    }
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(!is_present[a[i]]){
            is_present[a[i]]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
