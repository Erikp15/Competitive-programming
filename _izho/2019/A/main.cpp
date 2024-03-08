#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Size=1e3+10;

char ans[Size][Size];

void solve(){
    ll n,m;
    cin>>n>>m;
    if(n>m){
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                i%2==0 ? ans[j][i]='+' : ans[j][i]='-';
            }
        }
        if(m%2==0){
            for(ll i=0;i<n;i++){
                ans[i][m-1]='+';
            }
        }
    }else{
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                i%2==0 ? ans[i][j]='-' : ans[i][j]='+';
            }
        }
        if(n%2==0){
            for(ll i=0;i<m;i++){
                ans[n-1][i]='-';
            }
        }
    }
    cout<<max(n,m)+(min(n,m)-1)/2<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
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
3 3
1 5 1
2 3
1 1 5
2 3
*/
