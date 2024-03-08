#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;
vector<pair<ll,ll>> ans;

class DSU{
public:
    ll root[Size],ranking[Size];
    void add(ll v){
        root[v]=v;
        ranking[v]=1;
    }
    ll find_root(ll v){
        if(root[v]==v)return v;
        root[v]=find_root(root[v]);
        return root[v];
    }
    void merge_set(ll a,ll b){
        a=find_root(a);
        b=find_root(b);
        if(ranking[b]>ranking[a]){
            swap(a,b);
        }
        root[b]=a;
        ranking[a]=max(ranking[a],ranking[b]+1);
    }
};


void solve(){
    ll n,m1,m2;
    DSU a,b;
    cin>>n>>m1>>m2;
    for(ll i=1;i<=n;i++){
        a.add(i);
        b.add(i);
    }
    for(ll i=0;i<m1;i++){
        ll u,v;
        cin>>u>>v;
        a.merge_set(u,v);
    }
    for(ll i=0;i<m2;i++){
        ll u,v;
        cin>>u>>v;
        b.merge_set(u,v);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            //cout<<i<<" "<<j<<":"<<a.root[i]<<" "<<a.root[j]<<"   "<<i<<" "<<j<<":"<<b.root[i]<<" "<<b.root[j]<<"\n";
            if(a.find_root(i)!=a.find_root(j) and b.find_root(i)!=b.find_root(j)){
                a.merge_set(i,j);
                b.merge_set(i,j);
                ans.push_back({i,j});
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(ll i=0;i<(ll)ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
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
