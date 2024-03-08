#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
vector<ll> a[Size],pre[Size];
ll ans[Size],s[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        a[i].clear();
        pre[i].clear();
        ans[i]=0;
    }
    for(ll i=0;i<n;i++){
        cin>>s[i];
        s[i]--;
    }
    for(ll i=0;i<n;i++){
        ll v;
        cin>>v;
        a[s[i]].push_back(v);
    }
    for(ll i=0;i<n;i++){
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());
    }
    ll total_sum=0;
    for(ll i=0;i<n;i++){
        if(a[i].empty())continue;
        pre[i].push_back(a[i][0]);
        total_sum+=a[i][0];
        for(ll j=1;j<(ll)a[i].size();j++){
            pre[i].push_back(pre[i][j-1]+a[i][j]);
        }
    }
    for(ll i=0;i<=n;i++){
        ans[i]=0;
    }
    for(ll i=0;i<n;i++){
        if(a[i].empty())continue;
        for(ll k=1;k<=a[i].size();k++){
            ans[k]+=pre[i][(a[i].size()/k*k)-1];
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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
