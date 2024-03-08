#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=2e5+1;
pair<ll,string> a[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    ll min_0=1e18,min_1=1e18,min_01=1e18;
    for(ll i=0;i<n;i++){
        if(a[i].second[0]=='1'){
            min_0=a[i].first;
            break;
        }
    }
    for(ll i=0;i<n;i++){
        if(a[i].second[1]=='1'){
            min_1=a[i].first;
            break;
        }
    }
    for(ll i=0;i<n;i++){
        if(a[i].second[0]=='1' and a[i].second[1]=='1'){
            min_01=a[i].first;
            break;
        }
    }
    ll ans=min(min_0+min_1,min_01);
    if(ans==1e18){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
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
