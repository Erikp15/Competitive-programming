#include <iostream>

using namespace std;

typedef long long ll;

class edge{
    ll s,e;
};

    const Size=2e5+1;
    vector<ll> adj[Size];
    vector<edge> edges;

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);

        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    solve();
    while(t--){
        ll type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            adj[]
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
