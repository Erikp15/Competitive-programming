#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll n,seg_tree[4*Size],a[Size];

    void build(ll i,ll cl,ll cr){
        if(cl==cr){
            seg_tree[i]=a[cl];
        }else{
            build(i*2,cl,(cl+cr)/2);
            build(i*2+1,(cl+cr)/2+1,cr);
            seg_tree[i]=max(seg_tree[i*2],seg_tree[i*2+1]);
        }
    }

    ll sum(ll i,ll cl,ll cr,ll l,ll r) {
        if(l>r){
            return 0;
        }
        if(l==cl && r==cr) {
            return seg_tree[i];
        }
        ll cm=(cl+cr)/2;
        ll ls=sum(i*2,cl,cm,l,min(r,cm));
        ll rs=sum(i*2+1,cm+1,cr,max(l,cm+1),r);
        return max(ls,rs);
    }

    void update(ll i,ll cl,ll cr,ll tar,ll val){
        ll cm=(cl+cr)/2;
        if(tar==cl and tar==cr){
            seg_tree[i]=val;
        }else{
            if(tar<=cm){
                update(i*2,cl,cm,tar,val);
            }
            if(tar>cm){
                update(i*2+1,cm+1,cr,tar,val);
            }
            seg_tree[i]=seg_tree[i*2]+seg_tree[i*2+1];
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        ll t; cin>>t;
        if(t==1){
            ll l,r;
            cin>>l>>r;
            cout<<sum(1,0,n-1,l,r)<<endl;
        }
        if(t==2){
            ll index,val;
            cin>>index>>val;
            update(1,0,n-1,index,val);
        }
    }
    return 0;
}
/*
5
1 3 -2 8 -7
5
1 0 3
1 1 4
2 3 -10
1 0 3
1 1 4
*/
