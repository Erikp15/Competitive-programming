#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e6+2,mod=1e9+7;
vector<ll> adj[Size];
ll dp[Size];
bool visited[Size];
ll n,m;

void solve(){
    dp[1]=1;
    dp[2]=5;
    dp[3]=10;
    ll curr_row=3,curr_pos=0;
    for(ll i=4;i<=1e6;i++){
        ll l=i-curr_row+curr_pos,r=i-curr_row+curr_pos+1;
        if(curr_pos==0){
            dp[i]=dp[r]+i*i;
            curr_pos++;
            continue;
        }
        if(curr_pos==curr_row){
            dp[i]=dp[l]+i*i;
            curr_pos=0;
            curr_row++;
            continue;
        }
        if(curr_pos<=curr_row/2){
            dp[i]=dp[r]+i*i;
            dp[i]=

        }else{
            dp[i]=dp[l]+i*i;
        }
    }
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
/*
1
3 2
1 2
2 3
*/
