#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    bool is_coprime[100001];

    void solve(){
        ll n;
        cin>>n;
        string a,b;
        cin>>a;
        b=a;
        sort(b.begin(),b.end());
        ll k=n;
        for(ll i=0;i<n;i++){
            if(a[i]==b[i])k--;
        }
        cout<<k<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
