#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    string a = "codeforces";
    string b;
    cin>>b;
    int c=0;
    for(ll i=0;i<a.size();i++){
        if(b[i]!=a[i]){
            c++;
        }
    }
    cout<<c <<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0)
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
