#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    ll a[Size];
    vector<ll> all_gaps;

    void solve(){
        ll n,k,x;
        cin>>n>>k>>x;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(ll i=0;i<n-1;i++){
            ll curr_gap=a[i+1]-a[i];
            if(curr_gap>x){
                all_gaps.push_back(curr_gap);
            }
        }
        sort(all_gaps.begin(),all_gaps.end());
        ll ans=all_gaps.size()+1;
        for(ll i=0;i<all_gaps.size();i++,ans--){
            ll remove_k;
            cout<<all_gaps[i]<<" ";
            all_gaps[i]%x==0 ? remove_k=(all_gaps[i]/x)-1 : remove_k=all_gaps[i]/x;
            if(k-remove_k<0)break;
            k-=remove_k;
        }
        cout<<ans<<"\n";
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
/*
5 2 1
1 2 5 6 7
1

2 100 1
1 1000000000000000000
*/
