#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=4e4+1,mod=998244353;
    ll a[Size],comp[Size],b_d[Size],d[Size],best_d_c[Size],components=0,v[Size],sum_in_comp[Size];
    vector<ll> d_adj[Size],und_adj[Size],r_adj[Size];
    bool visited[Size];

    void dfs(ll node){
        visited[node]=true;
        comp[node]=components;
        sum_in_comp[components]++;
        for(auto it:d_adj[node]){
            if(!visited[it])dfs(it);
        }
    }

    void max_d(ll node,ll depth){
        v[node]=1;
        d[node]=depth;
        ll best_depth=depth;
        for(auto it:und_adj[node]){
            if(v[it]==1)continue;
            max_d(it,depth+1);
            best_depth=max(best_depth,b_d[it]);
        }
        b_d[node]=best_depth;
        v[node]=0;
    }

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]!=0){
                und_adj[i].push_back(a[i]-1);
                r_adj[a[i]-1].push_back(i);
                d_adj[i].push_back(a[i]-1);
                d_adj[a[i]-1].push_back(i);
            }
        }
        for(ll i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
                components++;
            }
        }
        bool is_scc=true;
        for(ll i=0;i<n;i++){
            if(r_adj[i].size()==0){
                is_scc=false;
                max_d(i,1);
            }
        }
        if(is_scc){
            cout<<components<<"\n";
            for(ll i=0;i<components;i++){
                cout<<sum_in_comp[i]<<"\n";
            }
            return;
        }
        for(ll i=0;i<n;i++){
            best_d_c[comp[i]]=max(best_d_c[comp[i]],b_d[i]);
        }
        cout<<components<<"\n";
        for(ll i=0;i<components;i++){
            cout<<best_d_c[i]<<"\n";
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
7
2
3
4
1
3
5
6

1
7

4
2
3
4
1

1
4
*/
