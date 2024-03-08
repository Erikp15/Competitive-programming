#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e3+1,m=1e9+7;
    ll grid[Size][Size],dp2[Size][Size],dp5[Size][Size];
    bool prev_2[Size][Size],prev_5[Size][Size];

    ll count_2(ll n){
        ll ans=0;
        while(n%2==0){
            n/=2;
            ans++;
        }
        return ans;
    }
    ll count_5(ll n){
        ll ans=0;
        while(n%5==0){
            n/=5;
            ans++;
        }
        return ans;
    }

    void solve(){
        ll n;
        cin>>n;
        bool is_one=false;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]==0){
                    grid[i][j]=10;
                    is_one=true;
                }
            }
        }
        dp2[0][0]=count_2(grid[0][0]);
        for(ll i=1;i<n;i++){
            dp2[0][i]=dp2[0][i-1]+count_2(grid[0][i]);
        }
        for(ll i=1;i<n;i++){
            dp2[i][0]=dp2[i-1][0]+count_2(grid[i][0]);
        }
        dp5[0][0]=count_2(grid[0][0]);
        for(ll i=1;i<n;i++){
            dp5[0][i]=dp5[0][i-1]+count_5(grid[0][i]);
        }
        for(ll i=1;i<n;i++){
            dp5[i][0]=dp5[i-1][0]+count_5(grid[i][0]);
        }
        for(ll i=1;i<n;i++){
            for(ll j=1;j<n;j++){
                if(dp2[i-1][j]<dp2[i][j-1]){
                    dp2[i][j]=dp2[i-1][j]+count_2(grid[i][j]);
                    prev_2[i][j]=false;
                }else{
                    dp2[i][j]=dp2[i][j-1]+count_2(grid[i][j]);
                    prev_2[i][j]=true;
                }
                if(dp5[i-1][j]<dp5[i][j-1]){
                    dp5[i][j]=dp5[i-1][j]+count_5(grid[i][j]);
                    prev_5[i][j]=false;
                }else{
                    dp5[i][j]=dp5[i][j-1]+count_5(grid[i][j]);
                    prev_5[i][j]=true;
                }
            }
        }
        if(is_one){
            cout<<min(min(dp2[n-1][n-1],dp5[n-1][n-1]),1)<<endl;

        }
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
1
5
1 2 3 4 5
5 4 2 3 1

*/
