#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;

vector<ll> adj[Size];
ll p[Size],s[Size],e[Size];
ll n;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>s[i];
    }
    for(ll i=0;i<n;i++){
        cin>>e[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll from,w;
        cin>>from>>w;
        if(w>0)
            ans+=w;
    }
    cout << ans << endl;
    return 0;
}
