#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a==0 and b==0){
        cout<<0<<"\n";
        return;
    }
    if(a==b){
        cout<<1<<"\n";
        return;
    }
    if(abs(a-b)%2==0){
        cout<<2<<"\n";
    }else{
        cout<<-1<<"\n";
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
*/
