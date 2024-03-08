#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=2e5+10;
ll n,m,q;
ll tin[Size],height[Size],lca_tree[6*Size],visited[Size],a[Size];
set<ll> all_pairs[Size],all_singles[Size];
vector<ll> adj[Size],euler_tour;

void dfs(ll curr_node,ll depth){
    tin[curr_node]=euler_tour.size();
    height[curr_node]=depth;
    visited[curr_node]=1;
    euler_tour.push_back(curr_node);
    for(auto itr:adj[curr_node]){
        if(!visited[itr]){
            dfs(itr,depth+1);
            euler_tour.push_back(curr_node);
        }
    }
}

void build_lca(ll l,ll r,ll i){
    if(l==r){
        lca_tree[i]=euler_tour[r];
    }else{
        ll mid=(l+r)/2;
        build_lca(l,mid,i*2);
        build_lca(mid+1,r,i*2+1);
        height[lca_tree[i*2]]<height[lca_tree[i*2+1]] ? lca_tree[i]=lca_tree[i*2] : lca_tree[i]=lca_tree[i*2+1];
    }
}

ll query_lca(ll l,ll r,ll i,ll tl,ll tr){
    if(r<tl or l>tr){
        return -1;
    }
    if(l==tl and r==tr){
        return lca_tree[i];
    }else{
        ll mid=(l+r)/2;
        ll n1=query_lca(l,mid,i*2,tl,min(mid,tr));
        ll n2=query_lca(mid+1,r,i*2+1,max(tl,mid+1),tr);
        if(n1==-1)return n2;
        if(n2==-1)return n1;
        return height[n1]<height[n2] ? n1 : n2;
    }
}

ll lca(ll a,ll b){
    if(a>n or a<1 or b>n or b<0)return 0;
    if(tin[a]>tin[b]) swap(a,b);
    return query_lca(0,euler_tour.size()-1,1,tin[a],tin[b]);
}

void solve(){
    cin>>n>>m>>q;
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(ll i=1;i<=m;i++){
        cin>>a[i];
    }
    dfs(1,1);
    build_lca(0,euler_tour.size()-1,1);
    for(ll i=1;i<=m;i++){
        ll Lca=lca(a[i],a[i+1]);
        all_pairs[Lca].insert(i);
        all_singles[a[i]].insert(i);
    }
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll pos,val;
            cin>>pos>>val;
            ll lca1=lca(a[pos-1],a[pos]);
            ll lca2=lca(a[pos],a[pos+1]);
            ll new_lca1=lca(a[pos-1],val);
            ll new_lca2=lca(val,a[pos+1]);
            all_singles[a[pos]].erase(pos);
            a[pos]=val;
            all_singles[a[pos]].insert(pos);
            all_pairs[lca1].erase(pos-1); all_pairs[lca2].erase(pos);
            all_pairs[new_lca1].insert(pos-1); all_pairs[new_lca2].insert(pos);
        }
        if(type==2){
            ll l,r,v;
            cin>>l>>r>>v;
            auto pair_found=all_pairs[v].lower_bound(l);
            auto single_found=all_singles[v].lower_bound(l);
            if(single_found!=all_singles[v].end() and *single_found<=r){
                cout<<*single_found<<" "<<*single_found<<"\n";
            }else{
                if(pair_found!=all_pairs[v].end() and *pair_found<r){
                    cout<<*pair_found<<" "<<*pair_found+1<<"\n";
                }else{
                    cout<<-1<<" "<<-1<<"\n";
                }
            }
        }
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
5 4 4
1 2
3 1
3 4
5 3
4 4 4 4
2 1 3 1
1 3 5
2 1 5 3
2 1 2 4

5 4 4
1 2
3 1
3 4
5 3
4 5 2 3
2 1 3 1
1 3 5
2 3 4 5
2 1 3 1
*/
