#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class tree{
public:
    ll sum;
    ll to_add;
};

    const ll Size=300001,m=10e9+9;
    ll n,q;
    ll a[Size],fib[Size],fib_sum[Size];
    tree seg_tree[4*Size];

    void build(ll i,ll cl,ll cr){
        if(cl==cr){
            seg_tree[i].sum=a[cr];
        }else{
            ll cm=(cl+cr)/2;
            build(i*2,cl,cm);
            build(i*2+1,cm+1,cr);
            seg_tree[i].sum=(seg_tree[i*2].sum+seg_tree[i*2+1].sum)%m;
        }
    }
    ll find_i(ll i,ll cl,ll cr,ll l,ll r,ll start){
        ll cm=(cl+cr)/2;
        if(l>r)return 0;
        if(cl==l and cr==r){
            return seg_tree[i].sum+(seg_tree[i].to_add*(fib_sum[r+1-start]-fib_sum[l+1-start]+fib[l+1-start])%m)%m;
        }else{
            ll n1=find_i(i*2,cl,cm,l,min(r,cm),start);
            ll n2=find_i(i*2+1,cm+1,cr,max(cm+1,l),r,start);
            return (n1+n2+(seg_tree[i].to_add*(fib_sum[r+1-start]-fib_sum[l+1-start]+fib[l+1-start]))%m)%m;
        }
    }
    void update(ll i,ll cl,ll cr,ll l,ll r){
        ll cm=(cl+cr)/2;
        if(l>r)return;
        if(cl==l and cr==r){
            seg_tree[i].to_add++;
        }else{
            update(i*2,cl,cm,l,min(r,cm));
            update(i*2+1,cm+1,cr,max(cm+1,l),r);
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<4*Size;i++){
        seg_tree[i].sum=0;
        seg_tree[i].to_add=0;
    }
    fib[0]=0; fib[1]=1;
    fib_sum[0]=0; fib_sum[1]=1;
    for(ll i=2;i<Size;i++){
        fib[i]=(fib[i-1]+fib[i-2])%m;
        fib_sum[i]=(fib_sum[i-1]+fib[i])%m;
    }
    build(1,0,n-1);
    for(ll i=0;i<q;i++){
        ll t;
        cin>>t;
        if(t==1){
            ll l,r;
            cin>>l>>r;
            l--; r--;
            update(1,0,n-1,l,r);
        }
        if(t==2){
            ll l,r;
            cin>>l>>r;
            l--; r--;
            cout<<find_i(1,0,n-1,l,r,l)<<endl;
        }
    }
    return 0;
}
/*
4 4
1 2 3 4
1 1 4
2 1 4
1 2 4
2 1 3
17
12

6 6
1 2 3 4 5 6
2 1 6
1 1 6
2 1 6
2 2 4
1 2 4
2 2 4
*/

