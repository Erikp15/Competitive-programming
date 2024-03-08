#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


void solve(){
    ll n;
    cin>>n;
    ll a[1001];
    ll best_so_far=0,curr=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        if(a[i]){
            best_so_far=max(best_so_far,curr);
            curr=0;
        }else{
            curr++;
        }
    }
    best_so_far=max(best_so_far,curr);
    cout<<best_so_far<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
