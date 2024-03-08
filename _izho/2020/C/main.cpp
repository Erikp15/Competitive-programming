#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e3+10;

ll a[Size],num_count[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll unique_nums=0;
    for(ll i=0;i<n;i++){
        ll k=i+1;
        for(ll j=i;j<n;j++){
            num_count[a[j]]++;
            if(num_count[a[j]]==1)
                unique_nums++;
            for(;k<n;k++){

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}
