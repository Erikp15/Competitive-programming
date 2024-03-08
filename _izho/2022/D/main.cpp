#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=81;

string a,b;
bool is_reachable[Size][Size][Size][Size],visited[Size][Size];
ll n;

void dfs(ll start_x,ll start_y,ll curr_x,ll curr_y){
    is_reachable[start_y][start_x][curr_y][curr_x]=1;
    visited[curr_y][curr_x]=1;
    if(curr_x<n-1 and a[curr_y]=='R' and !visited[curr_y][curr_x+1]){
        dfs(start_x,start_y,curr_x+1,curr_y);
    }
    if(curr_x>0 and a[curr_y]=='L' and !visited[curr_y][curr_x-1]){
        dfs(start_x,start_y,curr_x-1,curr_y);
    }
    if(curr_y>0 and b[curr_x]=='U' and !visited[curr_y-1][curr_x]){
        dfs(start_x,start_y,curr_x,curr_y-1);
    }
    if(curr_y<n-1 and b[curr_x]=='D' and !visited[curr_y+1][curr_x]){
        dfs(start_x,start_y,curr_x,curr_y+1);
    }
}

void solve(){
    ll q;
    cin>>n>>q;
    cin>>a>>b;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            dfs(i,j,i,j);
            for(ll k=0;k<n;k++){
                for(ll m=0;m<n;m++){
                    visited[k][m]=0;
                }
            }
        }
    }
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll x1,y1,x2,y2;
            cin>>y1>>x1>>y2>>x2;
            y1--; x1--; y2--; x2--;
            if(is_reachable[y1][x1][y2][x2]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
1
2 20
RL
DU
1 1 1 2 2

1
4 20
RLRL
DUDU
1 2 2 1 1
1 1 1 1 1


1
4 4
LRRL
UDDU
1 1 4 3 1
1 1 4 4 4
3 4
1 1 4 4 4
*/
