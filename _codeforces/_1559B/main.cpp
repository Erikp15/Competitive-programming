#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e4+1;

void solve(){
    string a,b,c;
    ll n;
    cin>>n>>a;
    b=a;
    if(b[0]=='?'){
        b[0]='B';
    }
    for(ll i=1;i<n;i++){

        if(b[i]=='?'){
            if(b[i-1]=='R'){
                b[i]='B';
            }else{
                b[i]='R';
            }
        }
    }
    ll ans1=0;
    for(ll i=1;i<n;i++){
        if(b[i]==b[i-1]){
            ans1++;
        }
    }
    c=a;
    if(c[0]=='?'){
        c[0]='R';
    }
    for(ll i=1;i<n;i++){
        if(c[i]=='?'){
            if(c[i-1]=='R'){
                c[i]='B';
            }else{
                c[i]='R';
            }
        }
    }
    ll ans2=0;
    for(ll i=1;i<n;i++){
        if(c[i]==c[i-1]){
            ans2++;
        }
    }
    if(ans1<ans2){
        cout<<b<<"\n";
    }else{
        cout<<c<<"\n";
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
