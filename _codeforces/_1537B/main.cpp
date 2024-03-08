#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        if(min(abs(1-x)+abs(1-y),abs(n-x)+abs(m-y))+n+m-2>min(abs(n-x)+abs(1-y),abs(1-x)+abs(m-y))+m+n-2){
            cout<<"1 1 "<<n<<" "<<m<<"\n";
        }else{
            cout<<"1 "<<m<<" "<<n<<" 1"<<"\n";
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
3
1 2 3
*/
