#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e6+1;

ll a[Size];
vector<ll> ans[Size];

void solve(){
    ll n,k,sum=0,m=0;
    cin>>n>>k;
    ll vals_to_change=n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%k!=0){
        cout<<-1<<"\n";
        return;
    }
    ll i=0;
    for(;vals_to_change-k>k and i<n;m++){
        for(ll j=0;j<k;i++,j++){
            ans[m].push_back(i+1);
            vals_to_change--;
        }
        ans[m].push_back(a[i]);
    }
    for(;i<n-k;i++,m++){

    }
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
