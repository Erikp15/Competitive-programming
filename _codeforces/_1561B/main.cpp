#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+2;

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<a+b<<"\n";
        for(ll i=0;i<=a+b;i+=2){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
    if(b>a)swap(a,b);
    ll min_k=(a-b)/2;
    ll max_k=2*b+(a-b)/2;
    if((a-b)%2==1)max_k++;
    cout<<max_k-min_k+1<<"\n";
    for(ll i=min_k;i<=max_k;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
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
