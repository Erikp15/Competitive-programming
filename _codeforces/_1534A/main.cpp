#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string a[51];
    bool visited[51][51];
    ll n,m;

    bool bfs(ll x,ll y){
        visited[x][y]=true;
        if(x!=n-1){
            if(a[x][y]==a[x+1][y]){
                return false;
            }
            if(a[x+1][y]=='.'){
                a[x+1][y]==
            }
        }
        if(x!=0){
            if(a[x][y]==a[x-1][y]){
                return false;
            }
        }
        if(y!=n-1){
            if(a[x][y]==a[x][y+1]){
                return false;
            }
        }
        if(y!=0){
            if(a[x][y]==a[x][y-1]){
                return false;
            }
        }
        if(x!=0){
            bfs(x-1,y);
        }
        if(x!=n-1){
            bfs(x+1,y);
        }
        if(y!=0){
            bfs(x,y-1);
        }
        if(y!=n-1){
            bfs(x,y+1);
        }
        return true;
    }

    void solve(){
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(a[i][j]!='.'){
                    if(bfs(i,j)){
                        cout<<"YES"<<"\n";
                        for(ll i=0;i<n;i++){
                            for(ll j=0;j<m;j++){
                                cout<<a[i][j];
                            }
                            cout<<"\n";
                        }
                    }else{
                        cout<<"NO"<<"\n";
                    }
                    return;
                }
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
4
0 2 1 3
1 3 0 2
*/
