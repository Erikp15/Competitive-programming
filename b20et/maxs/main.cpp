#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5*1e4+1;
ll a[Size],sum[Size],org_seg_tree[2*Size],seg_tree[2*Size];
vector<ll> all_div[Size+1];

void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i]=sum[l];
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        seg_tree[i]=max(seg_tree[i*2],seg_tree[i*2+1]);
    }
}
void update(ll t,ll v,ll l,ll r,ll i){
    if(l==r and r==t){
        seg_tree[i]+=v;
    }else{
        ll mid=(l+r)/2;
        if(t>mid){
            update(t,v,mid+1,r,i*2+1);
        }else{
            update(t,v,l,mid,i*2);
        }
        seg_tree[i]=max(seg_tree[i*2],seg_tree[i*2+1]);
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sum[0]=-1e18;
    for(ll i=1;i<=n;i++){
        for(ll j=i-1;j<n;j+=i){
            sum[i]+=a[j];
        }
        for(ll j=1;j<=sqrt(i);j++){
            if(i%j==0){
                all_div[i].push_back(j);
                if(j*j!=i){
                    all_div[i].push_back(i/j);
                }
            }
        }
    }
    build(1,n,1);
    ll m,ans=0;
    cin>>m;
    for(ll j=0;j<m;j++){
        ll pos,val;
        cin>>pos>>val;
        for(auto itr:all_div[pos]){
            update(itr,val,1,n,1);
        }
        ans+=seg_tree[1];
        for(auto itr:all_div[pos]){
            update(itr,-val,1,n,1);
        }
    }
    cout<<ans<<"\n";
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
