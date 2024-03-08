#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    ll a[Size];

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        ll min_diff=10e9+1;
        for(ll i=0;i<n-1;i++){
            min_diff=min(min_diff,abs(a[i]-a[i+1]));
        }
        pair<ll,ll> best_pair,best_index;
        bool taken=false;
        for(ll i=0;i<n-1;i++){
            if(abs(a[i]-a[i+1])==min_diff){
                if(a[i]==a[0] and a[i+1]==a[n-1]){
                    best_pair={a[i],a[i+1]};
                    best_index={i,i+1};
                    break;
                }
                if(a[i]==a[0] or a[i+1]==a[n-1]){
                    best_pair={a[i],a[i+1]};
                    best_index={i,i+1};
                    taken=true;
                }
                if(!taken){
                    best_pair={a[i],a[i+1]};
                    best_index={i,i+1};
                    taken=true;
                }
            }
        }
        cout<<best_pair.first<<" ";
        for(ll i=best_index.second+1;i<n;i++){
            cout<<a[i]<<" ";
        }
        for(ll i=0;i<best_index.first;i++){
            cout<<a[i]<<" ";
        }
        cout<<best_pair.second<<endl;
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
/*
1
3
1 2 3
*/
