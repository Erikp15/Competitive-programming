#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e6+1;

class node{
public:
    ll ans,largest,l,r;
};

ll w[Size];
node seg_tree[4*Size];

void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i].ans=0;
        seg_tree[i].largest=w[l];
        seg_tree[i].l=l;
        seg_tree[i].r=r;
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        ll max_v=seg_tree[i*2].largest,largest_swap=0;
        for(ll j=mid+1;j<=r;j++){
            if(w[j]<max_v and largest_swap<w[j]){
                largest_swap=w[j];
            }
        }
        seg_tree[i].l=seg_tree[i*2].l;
        seg_tree[i].r=seg_tree[i*2+1].r;
        seg_tree[i].largest=max(seg_tree[i*2].largest,seg_tree[i*2+1].largest);
        if(!largest_swap){
            seg_tree[i].ans=max(seg_tree[i*2].ans,seg_tree[i*2+1].ans);
        }else{
            seg_tree[i].ans=max(max(seg_tree[i*2].ans,seg_tree[i*2+1].ans),max_v+largest_swap);
        }
    }
}
node query(ll l,ll r,ll i,ll tl,ll tr){
    if(l>tr or r<tl){
        node a;
        a.ans=-1;
        return a;
    }
    if(l==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        node n1=query(l,mid,i*2,tl,min(tr,mid));
        node n2=query(mid+1,r,i*2+1,max(tl,mid+1),tr);
        node res;
        if(n1.ans==-1)return n2;
        if(n2.ans==-1)return n1;
        ll max_v=n1.largest,largest_swap=0;
        for(ll j=mid+1;j<=n2.r;j++){
            if(w[j]<max_v and largest_swap<w[j]){
                largest_swap=w[j];
            }
        }
        res.l=n1.l;
        res.r=n2.r;
        res.largest=max(n1.largest,n2.largest);
        if(!largest_swap){
            res.ans=max(n1.ans,n2.ans);
        }else{
            res.ans=max(max(n1.ans,n2.ans),max_v+largest_swap);
        }
        return res;
    }
}



void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>w[i];
    }
    build(0,n-1,1);
    while(m--){
        ll l,r,k;
        cin>>l>>r>>k;
        l--; r--;
        node res=query(0,n-1,1,l,r);
        cout<<(res.ans<=k)<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
5 2
3 5 1 8 2
1 3 6
2 5 3
1
0

5 3
3 1 5 1 3
2 4 5
1 5 7
1 3 4
1
0
*/
