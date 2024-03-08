#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+10;

ll a[Size];

ll find_ans(ll l,ll r,ll depth){
    ll d=pow(2,depth);
    bool is_contained[Size];
    for(ll i=l;i<=r;i+=d){

    }
}

void solve(){
    ll x,y,n;
    cin>>n>>x>>y;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=1000){
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            l--; r--;
            ll ans=find_ans(l,r,0);
            cout<<ans<<endl;
        }
    }else{
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            cout<<((r-l)*y)+((r-l+1)*x)<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
5 4 1
1 1 1 1 1
3
1 2
1 5
2 4
9
24
14

6 4 1
1 2 3 2 1 2
3
1 4
1 6
2 4
9
14
9
*/
