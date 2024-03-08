#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;

class platform{
public:
    ll x,y,d;
};
bool comp(const platform& a,const platform& b){
    return a.y<b.y;
}

platform a[Size];
pair<ll,ll> seg_tree[4*Size];

void update(ll l,ll r,ll i,ll tl,ll tr,pair<ll,ll> val){
    if(l>tr or r<tl)return;
    if(l==tl and r==tr){
        seg_tree[i]=val;
    }else{
        ll mid=(l+r)/2;
        update(l,mid,i*2,tl,min(mid,tr),val);
        update(mid+1,r,i*2+1,max(tl,mid+1),tr,val);
    }
}

pair<ll,ll> query(ll l,ll r,ll i,ll t){
    if(l==t and r==t){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        if(mid>=t){
            pair<ll,ll> res=query(l,mid,i*2,t);
            return max(seg_tree[i],res);
        }else{
            pair<ll,ll> res=query(mid+1,r,i*2+1,t);
            return max(seg_tree[i],res);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i].x>>a[i].y>>a[i].d;
    sort(a,a+n,comp);
    for(ll i=0;i<n;i++){
        ll l=query(0,Size,1,a[i].x-1).second;
        ll r=query(0,Size,1,a[i].x+a[i].d).second;
        pair<ll,ll> upd_val={a[i].y,min(l,r)+1};
        update(0,Size,1,a[i].x,a[i].x+a[i].d-1,upd_val);
    }
    ll t;
    cin>>t;
    while(t--){
        ll j;
        cin>>j;
        cout<<query(0,Size,1,j).second<<" ";
    }
    cout<<endl;
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
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
2 2 4 4 2
*/
