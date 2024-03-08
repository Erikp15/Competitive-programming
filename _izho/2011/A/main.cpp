#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=3e5+1;
pair<ll,ll> points[Size];
map<ll,set<ll>> x_coord,y_coord;

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
        x_coord[points[i].first].insert(points[i].second);
        y_coord[points[i].second].insert(points[i].first);
    }
    for(ll i=0;i<n;i++){
        ans+=(x_coord[points[i].first].size()-1)*(y_coord[points[i].second].size()-1);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
