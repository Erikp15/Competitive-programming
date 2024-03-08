#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll n,m,q;
    ll height[Size],toe[Size],seg_tree[8*Size];
    vector<ll> adj[Size],euler;
    bool visited[Size];

    void dfs(ll curr_node,ll depth){
        visited[curr_node]=true;
        toe[curr_node]=euler.size();
        height[curr_node]=depth;
        euler.push_back(curr_node);
        for(ll i=0;i<adj[curr_node].size();i++){
            if(!visited[adj[curr_node][i]]){
                dfs(adj[curr_node][i],depth+1);
                euler.push_back(curr_node);
            }
        }
    }

    void build(ll i,ll cl,ll cr){
        if(cl==cr){
            seg_tree[i]=euler[cr];
        }else{
            ll cm=(cr+cl)/2;
            build(i*2,cl,cm);
            build(i*2+1,cm+1,cr);
            seg_tree[i]=(height[seg_tree[i*2]]>height[seg_tree[i*2+1]]) ? seg_tree[i*2+1] : seg_tree[i*2];
        }
    }

    ll query(ll i,ll cl,ll cr,ll l,ll r){
        if(cl<l or cr>r)return 10e17;
        if(cl>=l and cr>=r){
            return seg_tree[i];
        }else{
            ll cm=(cr+cl)/2;
            ll n1=query(i*2,cl,cm,l,r);
            ll n2=query(i*2+1,cm+1,cr,l,r);
            if(n1==10e17)return n2;
            if(n2==10e17)return n1;
            return (height[n1]<height[n2]) ? n1 : n2;
        }
    }

    ll lca(ll l, ll r) {
        l=toe[l];
        r=toe[r];
        if(l>r)swap(l,r);
        return query(1,0,euler.size()-1,l,r);
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    build(1,0,euler.size()-1);
    cin>>q;
    for(ll i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        cout<<lca(l,r)<<endl;
    }
    return 0;
}
/*
7 6
1 2
1 3
1 4
2 5
2 6
4 7
4
5 6
*/
