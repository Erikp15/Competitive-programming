#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=400001,m=1e9+7;
    ll a[Size],b[Size],chain_count=0;
    bool visited[Size];
    map<ll,ll> a_2_b;

    void chain_search(ll curr_node){
        visited[curr_node]=true;
        if(visited[a_2_b[curr_node]]){
            chain_count++;
            return;
        }
        chain_search(a_2_b[curr_node]);
    }

    void solve(){
        ll n;
        cin>>n;
        a_2_b.clear();
        chain_count=0;
        for(ll i=0;i<=n;i++){
            visited[i]=false;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        for(ll i=0;i<n;i++){
            if(a[i]==b[i]){
                cout<<0<<"\n";
                return;
            }
            a_2_b[a[i]]=b[i];
        }
        for(ll i=0;i<n;i++){
            if(!visited[a[i]]){
                chain_search(a[i]);
            }
        }
        ll ans=1;
        for(ll i=0;i<chain_count;i++){
            ans=(ans*2)%m;
        }
        cout<<ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 4 5
5 4 2 3 1

*/
