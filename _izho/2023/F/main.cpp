#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct edge{
    ll to,l,r;
};


const ll Size=1e5+1;
vector<pair<ll,ll>> segments;
pair<ll,ll> seg_tree[6*Size];
vector<edge> adj[Size];
bool visited[Size];
ll n,m;

void reset_visited(){
    for(ll i=1;i<=n;i++){
        visited[i]=false;
    }
}

void dfs(ll curr_node,ll time){
    visited[curr_node]=true;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node.to] and next_node.l<=time and next_node.r>=time){
            dfs(next_node.to,time);
        }
    }
}

void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i]=segments[l];
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        if(seg_tree[i*2].second<seg_tree[i*2+1].first or seg_tree[i*2].first>seg_tree[i*2+1].second){
            seg_tree[i]={0,-1};
        }else{
            seg_tree[i].first=max(seg_tree[i*2].first,seg_tree[i*2+1].first);
            seg_tree[i].second=min(seg_tree[i*2].second,seg_tree[i*2+1].second);
        }
    }
}

pair<ll,ll> query(ll l,ll r,ll tl,ll tr,ll i){
    if(tl>r or tr<l)
        return {0,-1};
    if(tl==l and tr==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        pair<ll,ll> n1=query(l,mid,tl,min(mid,tr),i*2);
        pair<ll,ll> n2=query(mid+1,r,max(tl,mid+1),tr,i*2+1);
        if(n1.second==-1){
            return n2;
        }
        if(n2.second==-1){
            return n1;
        }
        pair<ll,ll> res;
        if(n1.second<n2.first or n1.first>n2.second){
            return {0,-1};
        }else{
            res.first=max(n1.first,n2.first);
            res.second=min(n1.second,n2.second);
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll from,to,l,r;
        cin>>from>>to>>l>>r;
        segments.push_back({l,r});
        if(l>r)
            swap(l,r);
        edge tmp;
        tmp.to=to;
        tmp.l=l;
        tmp.r=r;
        adj[from].push_back(tmp);
        tmp.to=from;
        adj[to].push_back(tmp);
    }
    build(0,m-1,1);
    ll q=n;
    cin>>q;
    while(q--){
        ll from,to,l,r;
        cin>>from>>to>>l>>r;
        if(n<=100 and q<=100 and l<=100 and r<=100){
            ll ans=0;
            for(ll i=l;i<=r;i++){
                dfs(from,i);
                if(visited[to]){
                    ans++;
                }
                reset_visited();
            }
            cout<<ans<<endl;
        }else{
            if(from>to)
                swap(from,to);
            from--; to--;
            pair<ll,ll> ans=query(0,m-1,from,to-1,1);
            if(ans.second==-1 or ans.second<l or ans.first>r){
                cout<<0<<endl;
            }else{
                ll r_bound=min(ans.second,r);
                ll l_bound=max(ans.first,l);
                if(r_bound<=l_bound){
                    cout<<0<<endl;
                }else{
                    cout<<r_bound-l_bound+1<<endl;
                }
            }
        }
    }
    return 0;
}
/*
5 4
1 2 1 3
2 3 3 4
3 4 1 5
4 5 3 4
10
1 3 3 3

4 3
1 2 2 5
2 3 1 4
3 4 2 3
3
1 3 1 5
4 2 2 4
1 4 3 6

3 2
1 2 1 50000
2 3 2 4000
10
1 3 1 131234
1 3 1 232321
1 3 1 3321
1 3 1 423
1 3 2311 35435
1 3 1 6192
1 3 0 1000000

2 1
1 2 4 5
10
1 2 4 4


*/
