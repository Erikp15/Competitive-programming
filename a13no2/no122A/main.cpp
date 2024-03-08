#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;

ll root[Size],size_of[Size];
bool visited[Size];
string ans;

void create_node(ll node){
    root[node]=node;
    size_of[node]=1;
}

ll find_root(ll node){
    if(root[node]==node)
        return node;
    return find_root(root[node]);
}

void merge_nodes(ll node1,ll node2){
    ll root1=find_root(node1);
    ll root2=find_root(node2);
    if(size_of[root1]<size_of[root2])
        swap(root1,root2);
    root[root2]=root1;
    size_of[root1]+=size_of[root2];
}

ll find_lca(ll node1,ll node2){
    queue<ll> to_process;
    to_process.push(node1);
    while(!to_process.empty()){
        ll curr_node=to_process.top();
        if(curr_node==node2)
        visited[curr_node]=true;

    }
}

void remove_edges(ll node1,ll node2){
    if(node1==root[node2]){
        root[node2]=node2;
        ll root1=find_root(node1);
        size_of[root1]-=size_of[node2];
    }
    if(node2==root[node1]){
        root[node1]=node1;
        ll root2=find_root(node2);
        size_of[root2]-=size_of[node1];
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0,from,to;i<m;i++){
        cin>>from>>to;
        if(!root[from])
            create_node(from);
        if(!root[to])
            create_node(to);
        if(find_root(from)!=find_root(to))
            merge_nodes(from,to);
    }
    ll q;
    cin>>q;
    for(ll i=0,type,from,to;i<q;i++){
        cin>>type>>from>>to;
        if(!root[from])
            create_node(from);
        if(!root[to])
            create_node(to);
        if(type==2){
            if(find_root(from)!=find_root(to))
                merge_nodes(from,to);
        }
        if(type==1){
            if(find_root(from)!=find_root(to)){
                ans+='0';
            }else{
                ans+='1';
            }
        }
        if(type==3){
            if(from==root[to] or to==root[from])
                remove_edges(from,to);
        }
    }
    cout<<ans<<endl;
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
4 2
1 2
2 3
3
1 2 3
3 1 3
1 2 3



9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
8
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
3 3 4
1 4 7
*/
