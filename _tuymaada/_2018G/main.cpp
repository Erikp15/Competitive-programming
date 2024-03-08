#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e5+1;
    pair<ll,ll> a[Size];
    ll n,m,c_count[Size];

    ll find_errors(){
        ll curr_count=1,ans=0;
        for(ll i=1;i<n;i++){
            if(a[i].first==a[i-1].first){
                if(a[i].second>a[i-1].second){
                    ans+=curr_count*(c_count[a[i].first]-i);
                    curr_count=0;
                }
                curr_count++;
            }
        }
        return ans;
    }

    void solve(){
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            c_count[a[i].first]++;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i].second;
        }
        sort(a,a+n);
        ll a1=find_errors();
        for(ll i=0;i<=n;i++)c_count[i]=0;
        for(ll i=0;i<n;i++){
            swap(a[i].first,a[i].second);
            c_count[a[i].first]++;
        }
        sort(a,a+n);
        cout<<(n*(n-1)/2)-(a1+find_errors())<<"\n";
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
