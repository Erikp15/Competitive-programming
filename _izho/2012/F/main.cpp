#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e7+7;
ll seg_tree[4*Size];

void update(ll l,ll r,ll i,ll tl,ll tr){
    if(tl>r or tr<l)return;
    if(tl==l and tr==r){
        seg_tree[i]=r-l+1;
    }else{
        ll mid=(l+r)/2;
        update(l,mid,i*2,tl,min(mid,tr));
        update(mid+1,r,i*2+1,max(mid+1,tl),tr);
        seg_tree[i]=seg_tree[i*2]+seg_tree[i*2+1];
        cout<<seg_tree[i*2]<<" "<<seg_tree[i*2+1]<<endl;
    }
}

ll query(ll l,ll r,ll i,ll tl,ll tr){
    if(tl>r or tr<l)return -1;
    if(tl==l and tr==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        ll n1=query(l,mid,i*2,tl,min(mid,tr));
        ll n2=query(mid+1,r,i*2+1,max(mid+1,tl),tr);
        if(n1==-1)return n2;
        if(n2==-1)return n1;
        return n1+n2;
    }
}

void solve(){
    ll m,c=0;
    cin>>m;
    for(ll i=0;i<m;i++){
        ll d,x,y;
        cin>>d>>x>>y;
        if(d==2){
            update(1,1e7,1,x+c,y+c);
        }
        if(d==1){
            ll q=query(1,1e7,1,x+c,y+c);
            c+=q;
            cout<<q<<"\n";
        }
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
