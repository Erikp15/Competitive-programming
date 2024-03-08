#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll n;
        cin>>n;
        ll curr=0;
        while(n%2==0){
            n/=2;
            curr++;
        }
        if(curr>0 and (n!=1 or curr%2==0)) {
            cout<<"Alice"<<"\n";
        }else{
            cout<<"Bob"<<"\n";
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
