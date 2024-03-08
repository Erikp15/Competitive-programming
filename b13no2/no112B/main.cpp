#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+10;

ll root[Size],depth[Size];
string ans;

void create(ll node){
    root[node]=node;
    depth[Size]=1;
}

ll find_root(ll node){
    if(root[node]==node)return node;
    return root[node]=find_root(root[node]);
}

void merge_nodes(ll node1,ll node2){
    node1=find_root(node1);
    node2=find_root(node2);
    if(depth[node1]<depth[node2])swap(node1,node2);
    root[node2]=node1;
    depth[node1]=max(depth[node1],depth[node2]+1);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        create(i);
    }
    for(ll i=0,from,to;i<m;i++){
        cin>>from>>to;
        if(find_root(from)!=find_root(to)){
            merge_nodes(from,to);
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll type,from,to;
        cin>>type>>from>>to;
        if(type==2){
            if(find_root(from)!=find_root(to)){
                merge_nodes(from,to);
            }
        }else{
            if(find_root(from)==find_root(to)){
                ans+='1';
            }else{
                ans+='0';
            }
        }
    }
    cout<<ans<<endl;
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
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
6
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
*/
