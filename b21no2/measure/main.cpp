#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1,m=1e9+7;
vector<pair<ll,ll> minn[4*Size];
ll ans[4*Size],small[4*Size],a[Size];

pair<ll,ll> query(ll l,ll r,ll i,ll tl,ll tr){
    if(r<tl or l>tr)return {-1,-1};
    if(tl==l and tr==r){
        return {ans[i],small[i]};
    }else{
        ll mid=(l+r)/2;
        pair<ll,ll> n1=query(l,mid,i*2,tl,min(tr,mid));
        pair<ll,ll> n2=query(mid+1,r,i*2+1,max(tl,mid+1),tr);
        if(n1.first==-1)return n2;
        if(n2.first==-1)return n1;
        for(ll )
    }
}

void build(ll l,ll r,ll i){
    if(l==r){
        ans[i]=a[l];
        small[i]=a[i];
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        ans[i]=(ans[i*2]+ans[i*2+1])%m;
        small[i]=min(small[i*2],small[i*2+1]);
    }
}



void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,n-1,1);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    find_all_primes();
    while(t--){
        solve();
    }
    return 0;
}
