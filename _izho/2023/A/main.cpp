#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;

const ll Size=2501;
ll n,m;
string a[Size];
ll grid[Size][Size];
ll squares_above[Size][Size];
ll pref[Size][Size];
ll left_dp[Size][Size];
ll right_dp[Size][Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool is_empt=true;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        for(ll j=0;j<a[i].size();j++){
            if(a[i][j]=='X'){
                grid[i][j]=-1;
                pref[i+1][j+1]=pref[i][j+1]+pref[i+1][j]-pref[i][j];
            }else{
                grid[i][j]=a[i][j]-'0';
                pref[i+1][j+1]=pref[i][j+1]+pref[i+1][j]-pref[i][j]+grid[i][j];
            }
        }
    }
    for(ll i=0;i<m;i++){
        ll last_x_id=-1;
        for(ll j=0;j<n;j++){
            if(grid[j][i]==-1){
                last_x_id=j;
            }
            squares_above[j][i]=j-last_x_id;
            //cout<<squares_above[j][i]<<" ";
        }
        //cout<<endl;
    }
    for(ll i=0;i<n;i++){
        ll last_x_id=-1;
        stack<pair<ll,ll>> smallest;
        for(ll j=0;j<m;j++){
            if(grid[i][j]==-1){
                last_x_id=j;
                while(!smallest.empty())
                    smallest.pop();
                continue;
            }
            while(!smallest.empty() and smallest.top().first>=squares_above[i][j]){
                smallest.pop();
            }
            if(smallest.empty()){
                if(last_x_id==-1){
                    left_dp[i][j]=pref[i+1][j+1]-pref[i-squares_above[i][j]+1][j+1];
                }else{
                    left_dp[i][j]=pref[i+1][j+1]-pref[i-squares_above[i][j]+1][j+1]-pref[i+1][last_x_id+1]+pref[i-squares_above[i][j]+1][last_x_id+1];
                }
            }else{
                ll last_id=smallest.top().second;
                left_dp[i][j]=left_dp[i][last_id]+pref[i+1][j+1]-pref[i-squares_above[i][j]+1][j+1]-pref[i+1][last_id+1]+pref[i-squares_above[i][j]+1][last_id+1];
            }
            smallest.push({squares_above[i][j],j});
        }
        while(!smallest.empty())
            smallest.pop();
        last_x_id=-1;
        for(ll j=m-1;j>=0;j--){
            if(grid[i][j]==-1){
                last_x_id=j;
                while(!smallest.empty())
                    smallest.pop();
                continue;
            }
            while(!smallest.empty() and smallest.top().first>=squares_above[i][j]){
                smallest.pop();
            }
            if(smallest.empty()){
                if(last_x_id==-1){
                    //ausdgf
                    right_dp[i][j]=pref[i+1][m]-pref[i-squares_above[i][j]+1][m]-pref[i+1][j]+pref[i-squares_above[i][j]+1][j];
                }else{
                    right_dp[i][j]=pref[i+1][last_x_id]-pref[i-squares_above[i][j]+1][last_x_id]-pref[i+1][j]+pref[i-squares_above[i][j]+1][j];
                }
            }else{
                ll last_id=smallest.top().second;
                right_dp[i][j]=right_dp[i][last_id]+pref[i+1][last_id]-pref[i-squares_above[i][j]+1][last_id]-pref[i+1][j]+pref[i-squares_above[i][j]+1][j];
            }
            smallest.push({squares_above[i][j],j});
        }
    }
    /*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<left_dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<right_dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=max(ans,right_dp[i][0]);
        for(ll j=0;j<m-1;j++){
            ans=max(ans,left_dp[i][j]+right_dp[i][j+1]);
        }
        ans=max(ans,left_dp[i][m-1]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
4 4
5175
3121
1119
2018
48

1 6
1X23X4
5

4 4
5175
312X
1XX9
20X8
19

4 5
12111
X1X1X
15122
22122
23
*/
