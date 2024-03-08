#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3e5+1;
    ll a[Size],b[Size],tin[Size],tout[Size],t=1,ans=0;
    vector<ll> a_adj[Size],b_adj[Size];
    set<pair<ll,ll>> big_set;

    ll add(ll node){
        auto it=big_set.lower_bound({tin[node],node});
        if(it!=big_set.end() and tout[it->second]<=tout[node])return -2;
        if(it==big_set.begin())return -1;
        it--;
        ll res=it->second;
        if(tout[node]>tout[res])return -1;
        big_set.erase(it);
        return res;
    }

    void dfs_a(ll node){
        ll res=add(node);
        if(res!=-2)big_set.insert({tin[node],node});
        ans=max(ans,(ll)big_set.size());
        for(ll v:a_adj[node])dfs_a(v);
        if(res!=-2){
            big_set.erase({tin[node],node});
            if(res!=-1)big_set.insert({tin[res],res});
        }
    }

    void dfs_b(ll node){
        tin[node]=t;
        t++;
        for(ll i=0;i<(ll)b_adj[node].size();i++){
            ll next_node=b_adj[node][i];
            dfs_b(next_node);
        }
        tout[node]=t;
    }


    void solve(){
        ll n;
        cin>>n;
        ans=0;
        t=1;
        for(ll i=2;i<=n;i++){
            cin>>a[i];
            a_adj[a[i]].push_back(i);
        }
        for(ll i=2;i<=n;i++){
            cin>>b[i];
            b_adj[b[i]].push_back(i);
        }
        dfs_b(1);
        dfs_a(1);
        cout<<ans<<"\n";
        for(ll i=1;i<=n;i++){
            a_adj[i].clear();
            b_adj[i].clear();
            big_set.clear();
            tin[i]=0;
            tout[i]=0;
            a[i]=0;
            b[i]=0;
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

