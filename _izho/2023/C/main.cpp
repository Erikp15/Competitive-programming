#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=101;
ll n;

vector<pair<ll,ll>> edges[Size];
ll free_node=3;
bool binary[65];

void solve(){
    ll a,b;
    cin>>a>>b;
    ll nodes=log2(a+b),most_sig=0;
    for(ll i=0;i<=nodes;i++){
        binary[i]=(1<<i)&a;
        if(binary[i]){
            most_sig=i;
        }
    }
    cout<<endl<<nodes+2<<" 3"<<endl;
    for(ll i=3;i<nodes+2;i++){
        if(binary[nodes+2-i]){
            cout<<i+1<<" 1"<<endl;
        }else{
            cout<<i+1<<" 2"<<endl;
        }
    }
    if(binary[0]){
        cout<<"2 1"<<endl;
    }else{
        cout<<"2 2"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=0,n;
    cin>>t>>n;
    while(t--){
        solve();
    }
    return 0;
}
