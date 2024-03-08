#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=1e6+1,mod=1e9+7;
ll catalan_num[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n=10000,m;
    cin>>n>>m;
    catalan_num[0]=1;
    catalan_num[1]=1;
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<i;j++){
            catalan_num[i]+=catalan_num[j]*catalan_num[i-1-j]%mod;
        }
    }
    string curr="(";
    ll curr_order=0;
    for(ll i=1;i<n;i++){
        ll close_count=catalan_num[n-i];
        if(){

        }
    }
    return 0;
}
