#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=500001;
    ll a[Size],long_left[Size],long_right[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll prev=10e18;
    for(ll i=0;i<n;i++){
        if(a[i]<prev){
            long_left[Size];
        }
    }
    for(ll i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/*
6
7 2 3 1 5 6
5
*/
