#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e4+10;

ll a[Size];
priority_queue<ll> tallest;

void solve(){
    ll n,ans=0;
    cin>>n;
    tallest.push(0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ll best=tallest.top();
        if(best>a[i]){
            ans+=best-a[i];
            tallest.pop();
            tallest.push(a[i]);
        }
        tallest.push(a[i]);
    }
    cout<<ans<<endl;
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
5
2 6 4 3 2
5

5
2 6 6 7 7
0
*/
