#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=4e5+2;

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(b<a)swap(a,b);
    ll n=(b-a)*2;
    if(a>n or b>n or c>n){
        cout<<-1<<"\n";
        return;
    }
    if((c+b-a)%n==0){
        cout<<n<<"\n";
        return;
    }
    cout<<(c+b-a)%n<<"\n";
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
