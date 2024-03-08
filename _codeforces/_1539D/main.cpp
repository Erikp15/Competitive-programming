#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    vector<ll> all_dis;
    pair<ll,ll> b_a[Size];

    void solve(){
        ll n,ans=0,items=0;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>b_a[i].second>>b_a[i].first;
        }
        sort(b_a,b_a+n);
        ll s=0,e=n-1;
        for(;s<e;){
            if(b_a[e].second-b_a[s].first+items<0){
                items+=b_a[e].second;
                ans+=b_a[e].second*2;
                b_a[e].second=0;
                e--;
            }else{
                ans+=(b_a[s].first-items)*2;
                b_a[e].second-=(b_a[s].first-items);
                items=b_a[s].first;
                ans+=b_a[s].second;
                items+=b_a[s].second;
                b_a[s].second=0;
                if(b_a[e].second<=0)e--;
                s++;
                while(items>=b_a[s].first and s<e){
                    ans+=b_a[s].second;
                    items+=b_a[s].second;
                    b_a[s].second=0;
                    s++;
                }
            }
        }
        if(s==e){
            ans+=b_a[s].second*2;
            ans-=max(b_a[s].second+min(items-b_a[s].first,(ll)0),(ll)0);
            items+=b_a[s].second;
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
3
3 4
1 3
1 5
8

5
2 7
2 8
1 2
2 4
1 8
12

8
1 8
1 6
1 5
1 3
1 3
1 8
1 7
1 3
11
*/
