#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3e5+1,mod=1e9+7;
    ll a[Size],in_pos[Size],comp=0;
    vector<ll> adj[Size];
    bool visited[Size];

    void dfs(ll node){
        visited[node]=true;
        for(ll i=0;i<(ll)adj[node].size();i++){
            if(!visited[adj[node][i]])dfs(adj[node][i]);
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        vector<ll> ans;
        for(ll i=0;i<n;i++)in_pos[i]=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }
        for(ll i=0;i<n;i++){
            ll start=i-a[i];
            if(start<0)start+=n;
            in_pos[start]++;
        }
        for(ll i=0;i<n;i++){
            if(in_pos[i]>=n-2*m){
                comp=0;
                for(ll j=0;j<n;j++){
                    ll start=(j+n-i)%n;
                    if(start<0)start+=n;
                    adj[a[j]].push_back(start);
                    adj[start].push_back(a[j]);
                }
                for(ll j=0;j<n;j++){
                    if(!visited[j]){
                        comp++;
                        dfs(j);
                    }
                }
                if(n-comp<=m){
                    ans.push_back(i);
                }
                for(ll j=0;j<n;j++){
                    adj[j].clear();
                    visited[j]=false;
                }
            }
        }
        cout<<ans.size()<<" ";
        for(ll i=0;i<(ll)ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        ans.clear();
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
