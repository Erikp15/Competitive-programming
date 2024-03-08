#include <bits/stdc++.h>

using namespace std;

typedef int ll;

struct range_update{
    ll time,dist,color;
    range_update(ll t,ll d,ll c){
        time=t;
        dist=d;
        color=c;
    }
};

struct centroid{
    ll parent,depth;
    vector<range_update> updates;
    vector<ll> children;
};

const ll Size=1e5+1;
ll n;
vector<pair<ll,ll>> adj[Size];
centroid centroid_tree[Size];
ll centroid_root=0;
ll depth[Size];
ll node_color[Size];
ll children_count[Size];
bool visited[Size];

void calc_depth(ll curr_node){
    visited[curr_node]=true;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node.first]){
            depth[next_node.first]=depth[curr_node]+next_node.second;
            calc_depth(next_node.first);
        }
    }
}

ll count_children(ll curr_node){
    visited[curr_node]=true;
    //cout<<curr_node<<endl;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node.first]){
            children_count[curr_node]+=count_children(next_node.first);
        }
    }
    return children_count[curr_node];
}

ll find_centroid(ll parent,ll curr_node){
    ll size_of_tree=children_count[curr_node]-1;
    ll to_move=-1;
    for(auto next_node:adj[curr_node]){
        if(next_node.first!=parent and !visited[next_node.first] and children_count[next_node.first]>size_of_tree/2){
            to_move=next_node.first;
            break;
        }
    }
    if(to_move!=-1){
        children_count[curr_node]=size_of_tree+1-children_count[to_move];
        children_count[to_move]=size_of_tree+1;
        return find_centroid(curr_node,to_move);
    }else{
        return curr_node;
    }
}

void decompose(ll start_node){
    queue<ll> to_process;
    start_node=find_centroid(-1,start_node);
    centroid_root=start_node;
    to_process.push(start_node);
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=true;
        for(auto next_node:adj[curr_node]){
            if(!visited[next_node.first]){
                ll next_centroid=find_centroid(curr_node,next_node.first);
                centroid_tree[next_centroid].parent=curr_node;
                centroid_tree[curr_node].children.push_back(next_centroid);
                centroid_tree[next_centroid].depth=centroid_tree[curr_node].depth+1;
                to_process.push(next_centroid);
            }
        }
    }
}

void update(ll curr_node,ll dist,ll color,ll time){
    if(centroid_tree[curr_node].updates.size()!=0){
        range_update last_update=centroid_tree[curr_node].updates.back();
        while(last_update.dist<dist){
            centroid_tree[curr_node].updates.pop_back();
            if(centroid_tree[curr_node].updates.size()==0)
                break;
            last_update=centroid_tree[curr_node].updates.back();
        }
    }
    centroid_tree[curr_node].updates.push_back(*new range_update(time,dist,color));
    if(curr_node!=centroid_root){
        update(centroid_tree[curr_node].parent,dist-(max(depth[curr_node],depth[centroid_tree[curr_node].parent])-min(depth[curr_node],depth[centroid_tree[curr_node].parent])),color,time);
    }
}

range_update find_update(ll l,ll r,ll curr_node,ll dist){
    ll mid=(l+r)/2;
    range_update curr=centroid_tree[curr_node].updates[mid];
    if(mid==centroid_tree[curr_node].updates.size()-1){
        if(curr.dist>=dist){
            return curr;
        }else{
            return find_update(l,mid,curr_node,dist);
        }
    }
    range_update right=centroid_tree[curr_node].updates[mid+1];
    if(curr.dist>=dist){
        if(right.dist<dist){
            return curr;
        }else{
            return find_update(mid+1,r,curr_node,dist);
        }
    }else{
        return find_update(l,mid,curr_node,dist);
    }
}

range_update query(ll curr_node,ll dist){
    if(centroid_tree[curr_node].updates.size()==0){
        range_update best_above=query(centroid_tree[curr_node].parent,(max(depth[curr_node],depth[centroid_tree[curr_node].parent])-min(depth[curr_node],depth[(int)centroid_tree[curr_node].parent])));
        return best_above;
    }
    range_update best_curr=find_update(0,centroid_tree[curr_node].updates.size()-1,curr_node,dist);
    if(curr_node==centroid_root){
        return best_curr;
    }
    range_update best_above=query(centroid_tree[curr_node].parent,(max(depth[curr_node],depth[centroid_tree[curr_node].parent])-min(depth[curr_node],depth[(int)centroid_tree[curr_node].parent])));
    if(best_curr.time<best_above.time){
        return best_curr;
    }else{
        return best_above;
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        children_count[i]=1;
    }
    for(ll i=0;i<n-1;i++){
        ll from=i,to=i+1,weight=1;
        //cin>>from>>to>>weight;
        //from--; to--;
        adj[from].push_back({to,weight});
        adj[to].push_back({from,weight});
    }
    //acount_children(0);
    ll a=0;
    for(ll i=0;i<10000000;i++){
        a+=i;
    }
    cout<<"cua;lksdf"<<endl;
    for(ll i=0;i<n;i++){
        centroid_tree[i].parent=-1;
        visited[i]=false;
    }
    decompose(0);
    for(ll i=0;i<n;i++){
        visited[i]=false;
    }
    //calc_depth(centroid_root);
    //update(centroid_root,1e9,0,1e9);
    ll q;
    cin>>q;
    while(q--){
        ll type,node;
        cin>>type>>node;
        node--;
        if(type==1){
            ll dist,color;
            cin>>dist>>color;
            update(node,dist,color,q);
        }else{
            range_update ans=query(node,0);
            cout<<ans.color<<endl;
        }
    }
    return 0;
}
/*
5
1 2 30
1 3 50
3 4 70
3 5 60
4
1 3 72 6
1 4 60 5
1 2 144 7
2 4

7
1 2 10
2 3 10
3 4 20
4 5 10
5 6 20
6 7 10

*/
