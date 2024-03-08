#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class tree{
public:
    ll smallest,add;
};

    const ll Size=200001;
    ll n,q,a[Size];
    tree seg_tree[4*Size];

    void build(ll i,ll cl,ll cr){
        if(cl==cr){
            seg_tree[i].smallest=a[cr];
            seg_tree[i].add=0;
        }else{
            ll cm=(cl+cr)/2;
            build(i*2,cl,cm);
            build(i*2+1,cm+1,cr);
            seg_tree[i].smallest=min(seg_tree[i*2].smallest,seg_tree[i*2+1].smallest);
            seg_tree[i].add=0;
        }
    }
    ll find_i(ll i,ll cl,ll cr,ll l,ll r){
        ll cm=(cl+cr)/2;
        if(l>r)return 10e17;
        if(cl==l and cr==r){
            return seg_tree[i].smallest+seg_tree[i].add;
        }else{
            ll n1=find_i(i*2,cl,cm,l,min(r,cm));
            ll n2=find_i(i*2+1,cm+1,cr,max(cm+1,l),r);
            return min(n1,n2)+seg_tree[i].add;
        }
    }
    void update(ll i,ll cl,ll cr,ll l,ll r,ll num){
        ll cm=(cl+cr)/2;
        if(l>r)return;
        if(cl==l and cr==r){
            seg_tree[i].add+=num;
        }else{
            update(i*2,cl,cm,l,min(r,cm),num);
            update(i*2+1,cm+1,cr,max(cm+1,l),r,num);
            seg_tree[i].smallest=min(seg_tree[i*2].smallest+seg_tree[i*2].add,seg_tree[i*2+1].smallest+seg_tree[i*2+1].add);
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<=4*n;i++){
        seg_tree[i].smallest=0;
        seg_tree[i].add=0;
    }
    build(1,0,n-1);
    cin>>q;
    for(ll i=0;i<q;i++){
        ll t=0,l,r;
        cin>>l>>r;
        string input;
        getline(cin,input);
        if(input.empty()){
            if(l>r){
                ll r1=find_i(1,0,n-1,l,n-1);
                ll r2=find_i(1,0,n-1,0,r);
                cout<<min(r1,r2)<<endl;
            }else{
                cout<<find_i(1,0,n-1,l,r)<<endl;
            }
        }else{
            ll num=0;
            bool is_neg=false;
            t++;
            if(input[t]=='-'){
                is_neg=true;
                t++;
            }
            for(;t<input.size();t++){
                num*=10;
                num+=input[t]-'0';
            }
            if(is_neg)num=-num;
            t++;
            if(l>r){
                update(1,0,n-1,l,n-1,num);
                update(1,0,n-1,0,r,num);
            }else{
                update(1,0,n-1,l,r,num);
            }
        }
    }
    return 0;
}
/*
4
1 2 3 4
6
3 0
3 1 -2
0 1
2 1
1 3 -3
0 3
ans:
1
-1
-1
-3

4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1
ans:
1
0
0
*/

