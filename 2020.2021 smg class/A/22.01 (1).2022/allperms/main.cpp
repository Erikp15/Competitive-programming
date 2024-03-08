#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=5;

vector<ll> input[Size];

void solve(){
    string s;
    for(ll i=0;getline(cin,s);i++){
        istringstream ss(s);
        cout<<s<<endl;
        for(ll j=0;j<s.size();j++){
            ll val;
            ss>>val;
            input[i].push_back(val);
        }
    }
    for(auto a:input){
        for(auto itr:a){
            cout<<itr<<" ";
        }
        //cout<<endl;
    }
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
/*
5 8
6 32.00
8 48.00
3 13.40
1 15.10
4 21.20
*/
