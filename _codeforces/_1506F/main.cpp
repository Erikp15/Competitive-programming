#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    pair<ll,ll> points[Size];

    void solve(){
        ll n,ans=0;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>points[i].first;
        }
        for(ll i=0;i<n;i++){
            cin>>points[i].second;
        }
        sort(points,points+n);
        pair<ll,ll> curr_point={1,1};
        for(ll i=0;i<n;i++){
            if(curr_point.first-curr_point.second==points[i].first-points[i].second and (curr_point.first-curr_point.second)%2==0){
                ans+=points[i].second-curr_point.second;     // susy
                curr_point={points[i].first,points[i].second};
                continue;
            }
            ll dist=(points[i].first-points[i].second)-(curr_point.first-curr_point.second);
            if((curr_point.first-curr_point.second)%2==0){
                ans+=dist/2;
            }else{
                dist%2==0 ? ans+=dist/2 : ans+=dist/2+1;
            }
            curr_point={points[i].first,points[i].second};
        }
        cout<<ans<<"\n";
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
4
3
1 4 2
1 3 1
2
2 4
2 3
2
1 1000000000
1 1000000000
4
3 10 5 8
2 5 2 4

0
1
999999999
2

*/
