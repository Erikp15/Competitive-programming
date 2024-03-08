#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Size=1e6+10;

ll y[Size],seg_tree[4*Size];

void update(ll l,ll r,ll i,ll tl,ll tr,ll val){
    if(l>tr or r<tl){
        return;
    }
    if(l==tl and r==tr){
        seg_tree[i]+=val;
    }else{
        ll mid=(l+r)/2;
        update(l,mid,i*2,tl,min(mid,tr),val);
        update(mid+1,r,i*2+1,max(mid+1,tl),tr,val);
    }
}
ll query(ll l,ll r,ll i,ll pos){
    if(l==r and l==pos){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        if(pos<=mid){
            return query(l,mid,i*2,pos)+seg_tree[i];
        }else{
            return query(mid+1,r,i*2+1,pos)+seg_tree[i];
        }
    }
}


void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>y[i];
    }
    for(ll i=0;i<n-1;i++){
        update(1,Size-10,1,min(y[i],y[i+1]),max(y[i],y[i+1]),1);
    }
    while(m--){
        ll type;
        cin>>type;
        if(type==1){
            ll i,val;
            cin>>i>>val;
            i--;
            if(i!=0){
                update(1,Size-10,1,min(y[i-1],y[i]),max(y[i-1],y[i]),-1);
                update(1,Size-10,1,min(y[i-1],val),max(y[i-1],val),1);
            }
            if(i!=n-1){
                update(1,Size-10,1,min(y[i],y[i+1]),max(y[i],y[i+1]),-1);
                update(1,Size-10,1,min(val,y[i+1]),max(val,y[i+1]),1);
            }
            y[i]=val;
        }
        if(type==2){
            ll h;
            cin>>h;
            cout<<query(1,Size-10,1,h)<<endl;
        }
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
3 3
1 5 1
2 3
1 1 5
2 3
*/
