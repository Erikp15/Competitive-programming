#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1,m=1e9+7;
    ll ans=0;
    ll to_ans[Size];
    vector<ll> adj[Size];

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(a>b){
                to_ans[b]++;
            }
            if(a<b){
                to_ans[a]++;
            }
        }
        for(ll i=1;i<=n;i++){
            if(to_ans[i]<=0)ans++;
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    solve();
    cin>>t;
    while(t--){
        ll state,a,b;
        cin>>state;
        if(state==1){
            cin>>a>>b;
            ll prev_a=to_ans[a],prev_b=to_ans[b];
            if(a<b){
                to_ans[a]++;
            }
            if(a>b){
                to_ans[b]++;
            }
            if(prev_a==0 and to_ans[a]!=0)ans--;
            if(prev_b==0 and to_ans[b]!=0)ans--;
        }
        if(state==2){
            cin>>a>>b;
            ll prev_a=to_ans[a],prev_b=to_ans[b];
            if(a<b){
                to_ans[a]--;
            }
            if(a>b){
                to_ans[b]--;
            }
            if(prev_a!=0 and to_ans[a]==0)ans++;
            if(prev_b!=0 and to_ans[b]==0)ans++;
        }
        if(state==3){
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
1
5
1 2 3 4 5
5 4 2 3 1

*/
