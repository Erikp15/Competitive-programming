#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    map<ll,ll> all_x_count,all_y_count;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        all_x_count[a]++;
        all_y_count[b]++;
    }
    ll max_so_far=0;
    for(auto itrv:all_x_count){
        max_so_far=max(max_so_far,itrv.second);
    }
    for(auto itrv:all_y_count){
        max_so_far=max(max_so_far,itrv.second);
    }
    cout<<max_so_far<<endl;
    return 0;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
4
*/
