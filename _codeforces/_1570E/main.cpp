#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll a[Size],b[Size],seg_tree[4*Size];
set<ll> non;

void build(ll l,ll r,ll i){
    if(l==r){
        if(non.find(l)!=non.end()){
            seg_tree[i]=-1;
            return;
        }
        seg_tree[i]=abs(a[i]-b[i]);
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        if(seg_tree[i*2]==-1 or seg_tree[i*2+1]){
            seg_tree[i]=-1;
        }else{
            seg_tree[i]=max(seg_tree[i*2],seg_tree[i*2+1]);
        }
    }
}

ll query(ll l,ll r,ll tl,ll tr,ll i){
    if(tl>r or tr<tl){
        return -2;
    }
    if(tl==l and tr==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        ll n1=query(l,mid,tl,min(tr,mid),i*2);
        ll n2=query(mid+1,r,max(tl,mid+1),tr,i*2+1);
        if(n1==-1 or n2==-1){
            return -1;
        }else{
            if(n1==-2){
                return n2;
            }
            if(n2==-2){
                return n1;
            }
            return max(n1,n2);
        }
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n;i++){
        if((a[i]<b[i] and i%2==0) or (a[i]>b[i] and i%2==1)){
            non.insert(i);
        }
    }
    build(0,n-1,1);
    for(ll i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        l--; r--;
        cout<<query(0,n-1,l,r,1)<<"\n";
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
*/
