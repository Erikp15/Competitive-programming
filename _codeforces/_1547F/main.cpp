#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    ll a[2*Size],seg_tree[4*Size],n;

    void build(ll l,ll r,ll i){
        if(l==r){
            seg_tree[i]=a[l];
        }else{
            ll mid=(l+r)/2;
            build(l,mid,i*2);
            build(mid+1,r,i*2+1);
            seg_tree[i]=__gcd(seg_tree[i*2],seg_tree[i*2+1]);
        }
    }
    ll _find(ll l,ll r,ll tl,ll tr,ll i){
        if(tl==l and tr==r){
            return seg_tree[i];
        }else{
            if(l>=r or tr<l or tl>r)return -1;
            ll mid=(l+r)/2;
            ll n1=_find(l,mid,tl,min(mid,tr),i*2);
            ll n2=_find(mid+1,r,max(mid+1,tl),tr,i*2+1);
            if(n1==-1){
                return n2;
            }
            if(n2==-1){
                return n1;
            }
            return __gcd(n1,n2);
        }
    }

    void b_search(ll l,ll r){
        ll mid=(l+r)/2;
        if(l==r){
            cout<<mid<<"\n";
            return;
        }
        ll curr=_find(0,2*n-1,0,0+mid,1),next;
        for(ll i=0;i<n-1;i++){
            next=_find(0,2*n-1,i+1,i+mid+1,1);
            if(curr!=next){
                b_search(mid+1,r);
                return;
            }
            curr=next;
        }
        b_search(l,mid);
    }

    void solve(){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=n;i<2*n;i++){
            a[i]=a[i-n];
        }
        build(0,2*n-1,1);
        b_search(0,n);
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
