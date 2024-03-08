#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll a[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];

    }
    if(n%2==1)n--;
    vector<pair<bool,bool>> small;
    for(ll i=1;i<n;i+=2){
        ans+=min(a[i-1],a[i]);
        if(a[i-1]==a[i]){
            small.push_back({true,true});
        }
        if(a[i-1]<a[i]){
            small.push_back({true,false});
        }
        if(a[i-1]>a[i]){
            small.push_back({false,true});
        }
    }
    for(ll i=1;i<small.size();i++){
        if(small[i].first)
    }
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
/*
*/
