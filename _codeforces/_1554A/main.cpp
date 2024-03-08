#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class num{
public:
    ll s,b,v;
};

    const ll Size=1e5+1,mod=1e9+7;
    ll a[Size];
    num seg_tree[2*Size];

    void build(ll l,ll r,ll i){
        if(l==r){
            seg_tree[i].s=a[l];
            seg_tree[i].b=a[l];
            seg_tree[i].v=seg_tree[i].s;
        }else{
            ll mid=(l+r)/2;
            build(l,mid,i*2);
            build(mid+1,r,i*2+1);
            seg_tree[i].s=min(seg_tree[i*2].s,seg_tree[i*2+1].s);
            seg_tree[i].b=max(seg_tree[i*2].b,seg_tree[i*2+1].b);
            seg_tree[i].v=max(max(seg_tree[i*2].v,seg_tree[i*2+1].v),seg_tree[i].s*seg_tree[i].b);
        }
    }

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<2*n;i++){
            seg_tree[i].s=0;
            seg_tree[i].b=0;
            seg_tree[i].v=0;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        build(0,n-1,1);
        cout<<seg_tree[1].v<<"\n";
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
