#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3e5+1;
    ll a[Size],seg_tree[2*Size];

    void build(ll l,ll r,ll i){
        if(l==r){
            seg_tree[i]=a[l];
        }else{
            ll mid=(l+r)/2;
            build(l,mid,i*2);
            build(mid+1,r,i*2+1);
            ll l_count=0,r_count=0;
            for(ll j=l;j<=r;j++){
                if(a[j]==seg_tree[i*2])l_count++;
                if(a[j]==seg_tree[i*2+1])r_count++;
            }
            if(l_count>r_count){
                seg_tree[i]=seg_tree[i*2];
            }else{
                seg_tree[i]=seg_tree[i*2+1];
            }
        }
    }

    ll find_ans(ll l,ll r,ll i,ll tl,ll tr){
        if(l>tr or r<tl or tl>tr)return -1;
        if(l==tl and r==tr){
            ll ans=0;
            for(ll j=l;j<=r;j++){
                if(a[j]==seg_tree[i])ans++;
            }
            return max(ans-(r-l+1-ans),(ll)0)+1;
        }else{
            ll mid=(l+r)/2;
            ll n1=find_ans(l,mid,i*2,tl,min(mid,tr));
            ll n2=find_ans(mid+1,r,i*2+1,max(mid+1,tl),tr);
            if(n1==-1)return n2;
            if(n2==-1)return n1;
            ll l_count=0,r_count=0;
            for(ll j=l;j<=r;j++){
                if(a[j]==seg_tree[i*2])l_count++;
                if(a[j]==seg_tree[i*2+1])r_count++;
            }
            ll ans=max(l_count,r_count);
            return max(ans-(r-l+1-ans),(ll)0)+1;
        }
    }

    void solve(){
        ll n,q;
        cin>>n>>q;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        build(0,n-1,1);
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            l--; r--;
            cout<<find_ans(0,n-1,1,l,r)<<"\n";
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
6 1
1 3 2 3 3 2
2 5
*/
