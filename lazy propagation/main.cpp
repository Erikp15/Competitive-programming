#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll n,q,a[Size];
    ll seg_tree[4*Size];
    bool marked[4*Size];

    void build(ll i,ll cl,ll cr){
        if(cl==cr){
            seg_tree[i]=a[cr];
        }else{
            division(i);
            ll cm=(cl+cr)/2;
            build(i*2,cl,cm);
            build(i*2+1,cm+1,cr);
            seg_tree[i]=0;
        }
    }
    void division(ll i){
        if(marked[i]){
            seg_tree[i*2]=seg_tree[i];
            seg_tree[i*2+1]=seg_tree[i];
            marked[i]=false;
            marked[i*2]=true;
            marked[i*2+1]=true;
        }
    }
    ll find_i(ll i,ll cl,ll cr,ll t){
        if(marked[i]){
            return seg_tree[i];
        }
        ll cm=(cl+cr)/2;
        if(t<=cm){
            return find_i(i*2,cl,cm,t);
        }else{
            return find_i(i*2+1,cm+1,cr,t);
        }
    }
    void update(ll i,ll cl,ll cr,ll l,ll r,ll num){
        ll cm=(cl+cr)/2;
        if(l>r)return;
        if(cl==l and cr==r){
            marked[i]=true;
            seg_tree[i]=num;
            return;
        }else{
            division(i);
            update(i*2,cl,cm,l,min(r,cm),num);
            update(i*2+1,cm+1,cr,max(cm+1,l),r,num);
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
    cin>>q;
    for(ll i=0;i<q;i++){
        ll t;
        cin>>t;
        if(t==1){
            ll i;
            cin>>i;
            cout<<find_i(1,0,n-1,i)<<endl;
        }
        if(t==2){
            ll l,r,num;
            cin>>l>>r>>num;
            update(1,0,n-1,l,r,num);
        }
    }
    return 0;
}
/*
5
1 3 -2 8 -7
6
1 0
1 1
2 0 3 4
1 0
1 1
1 2
*/

