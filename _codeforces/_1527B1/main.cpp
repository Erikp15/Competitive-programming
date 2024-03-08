#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+2;
string a;

bool is_pal(){
    ll n=a.size();
    for(ll i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            return false;
            to_pal++;
        }
    }
    return true;
}

void solve(){
    ll n;
    cin>>n;
    cin>>a;
    if(is_pal()){
        ll zeros=0;
        for(ll i=0;i<n;i++){
            if(a[i]=='0')zeros++;
        }
        if(n%2==1){
            if(a[n/2]=='0' and zeros>1){
                cout<<"ALICE"<<"\n";
                return;
            }
        }
        cout<<"BOB"<<"\n";
    }else{
        ll zeros=0;
        for(ll i=0;i<n;i++){
            if(a[i]=='0')zeros++;
        }
        if(n%2==1){
            if(a[n/2]=='0' and zeros==2){
                cout<<"DRAW"<<"\n";
                return;
            }
        }
        cout<<"ALICE"<<"\n";
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
