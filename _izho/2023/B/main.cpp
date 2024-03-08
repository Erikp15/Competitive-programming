#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e5+1;
ll n;
ll a[Size];
vector<ll> adj1[Size],adj2[Size];
ll sub1[Size],sub2[Size];
bool visited1[Size],visited2[Size];
unordered_map<ll,ll> g1_2_g2;
ll neighbors1[Size],neighbors2[Size];
pair<ll,ll> seg_tree[Size];
vector<ll> ordered;

/*
void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i]=0;
    }else{
        ll mid(l+r)/2;
        build(l,mid,i*2);
        build(l,mid,i*2+1);
        seg_tree[i]=min(seg_tree[i*2],seg_tree[i*2+1]);
    }
}


void update(ll l,ll r,ll t,ll v,ll i){
    if(l>t or r<t)
        return;
    if(l==t and r==t){
        seg_tree[i]=v;
    }else{
        ll mid=(l+r)/2;
        update(mid+1,r,t,v,i*2);
        update(l,mid,t,v,i*2+1);
        seg_tree[i]=min(seg_tree[i*2],seg_tree[i*2+1]);
    }
}

ll query(ll l,ll r,ll tl,ll tr,ll i){
    if(l>tr or r<tl)
        return -1;
    if(l==tl and r==tr){
        return seg_tree[i];
    }else{
        ll mid(l+r)/2;
        ll a1=query(l,mid,tl,min(tl,tr),i*2);
        ll a2=query(mid+1,r,max(tl,mid+1),tr,i*2+1);
        if(a1==-1)
            return a2;
        if(a2==-1)
            return a1;
        return min(a1,a2);
    }
}
*/
void reset_visited(){
    for(ll i=1;i<=n;i++){
        visited1[i]=false;
        visited2[i]=false;
    }
}

void calc_sub1(ll curr_node){
    visited1[curr_node]=true;
    for(auto next_node:adj1[curr_node]){
        if(!visited1[next_node]){
            calc_sub1(next_node);
            sub1[curr_node]+=sub1[next_node];
        }
    }
}

void calc_sub2(ll curr_node){
    visited1[curr_node]=true;
    for(auto next_node:adj2[curr_node]){
        if(!visited1[next_node]){
            calc_sub2(next_node);
            sub2[curr_node]+=sub2[next_node];
        }
    }
}

void get_order(ll curr_node1,ll curr_node2,ll depth){
    visited1[curr_node1]=true;
    visited2[curr_node2]=true;
    g1_2_g2[curr_node2]=depth;
    cout<<curr_node1<<endl;
    cout<<curr_node1<<endl;
    ordered.push_back(curr_node1);
    ll next1=0,next2=0;
    for(auto next_node:adj1[curr_node1]){
        if(!visited1[next_node]){
            next1=next_node;
        }
    }
    for(auto next_node:adj2[curr_node2]){
        if(!visited2[next_node]){
            next2=next_node;
        }
    }
    if(next1==0 or next2==0){
        get_order(next1,next2,depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        sub1[i]=1;
        sub2[i]=1;
    }
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        adj1[from].push_back(to);
        adj1[to].push_back(from);
        neighbors1[from]++;
        neighbors1[to]++;
    }
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        adj2[from].push_back(to);
        adj2[to].push_back(from);
        neighbors2[from]++;
        neighbors2[to]++;
    }
    calc_sub1(1);
    reset_visited();
    calc_sub2(1);
    reset_visited();
    ll start1=0,start2=0;
    for(ll i=1;i<=n;i++){
        if(neighbors1[i]==1){
            start1=i;
        }
        if(neighbors2[i]==1){
            start2=i;
        }
    }
    get_order(start1,start2,1);
    /*
    for(ll i=0;i<ordered.size();i++){
        cout<<ordered[i]<<endl;
    }
    cout<<endl;
    */
    return 0;
}
/*
3
1 2
2 3
1 3
2 3


5
1 4
2 4
3 2
3 5
3 1
2 3
5 2
4 2

5
1 2
2 3
3 4
4 5
5 3
3 1
1 2
2 4
*/
