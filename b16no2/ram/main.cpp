#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e9+10;

vector<pair<ll,ll>> ans;

void solve(){
    ll k;
    cin>>k;
    for(ll i=1;i<sqrt(k);i++){
        if(k==2*i*i+1){
            ans.push_back({i,i});
            continue;
        }
        ll n=2*i*(i+1)+(i+1)-i;
        if(n>k)break;
        if(k==n){
            ans.push_back({i,i+1});
            continue;
        }
        if(k==n+1){
            ans.push_back({i+1,i});
            continue;
        }
        if((k-n)%(2*i+1)==0){
            ans.push_back({i,(k-n)/(2*i+1)+i+1});
        }
        if((k-n-1)%(2*i+1)==0){
            ans.push_back({(k-n-1)/(2*i+1)+i+1,i});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto itr:ans){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
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
