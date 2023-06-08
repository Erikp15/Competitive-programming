#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
ll a[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    pair<ll,ll> ans={0,0};
    for(ll i=0;i<n;i++){
        if(ans.first<a[i]*(n-i)){
            ans.first=a[i]*(n-i);
            ans.second=a[i];
        }

    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
