#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=3e5+10;

ll a[Size];
pair<ll,ll> diff[Size];

void solve(){
    ll n;
    cin>>n;
    bool is_not=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>3){
            is_not=1;
        }
    }
    ll s=0;
    for(ll i=1;i<n;i++){
        ll c=1;
        if(i==1){
            diff[s++]={a[i]-a[i-1],c};
            continue;
        }
        while(a[i]-a[i-1]==diff[s-1].first and i<n){
            i++;
            c++;
        }
        if(c>1){
            ll sum=(a[i-1]-a[i-2])*c;
            diff[s-1]={sum,1};
        }
        if(i<n){
            diff[s++]={a[i]-a[i-1],1};
        }
    }
    if(is_not){
        cout<<max(__builtin_popcount(n-1)+1,2)<<endl;
    }else{
        cout<<s+1<<endl;
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
/*
1
6
1 1 1 2 2 2
*/
