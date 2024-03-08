#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=2e5+1;
vector<ll> adj[Size];
bool visited[Size];
ll below[Size],above[Size];
ll neighbors[Size];
ll r[Size];
ll b[Size];
ll depth[Size];
ll first_occ[Size];
ll ancestors[20][Size];
ll n;
vector<ll> euler_path;
ll seg_tree[6*Size];

void reset_visited(){
    for(ll i=1;i<=n;i++){
        visited[i]=false;
    }
}

void dfs(ll curr_node){
    visited[curr_node]=true;
    below[curr_node]=1;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node]){
            dfs(next_node);
            below[curr_node]+=below[next_node];
        }
    }
}

void compute_ancestors(ll prev_node,ll curr_node){
    visited[curr_node]=1;
    ancestors[0][curr_node]=prev_node;
    //cout<<curr_node<<": "<<ancestors[0][curr_node]<<" ";
    for(ll i=1,id=1;id<=depth[curr_node];i++){
        id*=2;
        ancestors[i][curr_node]=ancestors[i-1][ancestors[i-1][curr_node]];
        //cout<<ancestors[i][curr_node]<<" ";
    }
    //cout<<endl;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node])
            compute_ancestors(curr_node, next_node);
    }
}

void euler_tour(ll curr_node,ll d){
    visited[curr_node]=true;
    depth[curr_node]=d;
    euler_path.push_back(curr_node);
    first_occ[curr_node]=euler_path.size()-1;
    for(auto next_node:adj[curr_node]){
        if(!visited[next_node]){
            euler_tour(next_node,d+1);
            euler_path.push_back(curr_node);
        }
    }
}

void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i]=euler_path[l];
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        if(depth[seg_tree[i*2]]<depth[seg_tree[i*2+1]]){
            seg_tree[i]=seg_tree[i*2];
        }else{
            seg_tree[i]=seg_tree[i*2+1];
        }
    }
}

ll query(ll l,ll r,ll tl,ll tr,ll i){
    if(tl>r or tr<l)
        return -1;
    if(tl==l and tr==r){
        return seg_tree[i];
    }else{
        ll mid=(l+r)/2;
        ll n1=query(l,mid,tl,min(mid,tr),i*2);
        ll n2=query(mid+1,r,max(tl,mid+1),tr,i*2+1);
        if(n1==-1){
            return n2;
        }
        if(n2==-1){
            return n1;
        }
        if(depth[n1]<depth[n2]){
            return n1;
        }else{
            return n2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    bool is_star=1;
    for(ll i=1;i<=n;i++){
        first_occ[i]=-1;
    }
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
        if(from!=1){
            is_star=false;
        }
        neighbors[from]++;
        neighbors[to]++;
    }
    dfs(1);
    reset_visited();
    euler_tour(1,0);
    build(0,euler_path.size()-1,1);
    for(ll i=1;i<=n;i++){
        above[i]=n-below[i];
        //cout<<"help:"<<below[i]<<" "<<above[i]<<endl;
    }
    reset_visited();
    compute_ancestors(0,1);
    ll q;
    cin>>q;
    while(q--){
        ll r_count, b_count;
        cin>>r_count;
        for(ll i=0;i<r_count;i++){
            cin>>r[i];
        }
        cin>>b_count;
        for(ll i=0;i<b_count;i++){
            cin>>b[i];
        }

        ll lca=query(0, euler_path.size()-1, min(first_occ[b[0]],first_occ[r[0]]), max(first_occ[b[0]],first_occ[r[0]]), 1);
        ll total_dist=depth[r[0]]+depth[b[0]]-2*depth[lca]-1;
        if(total_dist==0){
            if(depth[r[0]]>depth[b[0]]){
                cout<<below[r[0]]<<":"<<above[r[0]]<<endl;
            }else{
                cout<<above[b[0]]<<":"<<below[b[0]]<<endl;
            }
            continue;
        }
        if(total_dist==1){
            cout<<n<<":0"<<endl;
            continue;
        }
        ll r_dist=(total_dist-2)/2+(total_dist-2)%2;
        ll b_dist=(total_dist-2)/2;
        if(r_dist>=depth[r[0]]-depth[lca]){
            r_dist=r_dist-depth[r[0]]+depth[lca];
            r_dist=depth[b[0]]-depth[lca]-r_dist;
            ll curr_b_node=b[0];
            ll curr_r_node=b[0];

            for(ll i=0;b_dist>0;i++){
                if(b_dist%2==1){
                    curr_b_node=ancestors[i][curr_b_node];
                }
                b_dist/=2;
            }


            for(ll i=0;r_dist>0;i++){
                if(r_dist%2==1){
                    curr_r_node=ancestors[i][curr_r_node];
                }
                r_dist/=2;
            }

            if(above[ancestors[1][curr_b_node]]>below[curr_b_node]){
                cout<<above[curr_b_node]<<":"<<below[curr_b_node]<<endl;
                continue;
            }else{
                cout<<above[ancestors[1][curr_b_node]]<<":"<<below[ancestors[1][curr_b_node]]<<endl;
                continue;
            }
        }
        if(b_dist>=depth[b[0]]-depth[lca]){
            b_dist=b_dist-depth[r[0]]+depth[lca];
            b_dist=depth[r[0]]-depth[lca]-b_dist;
            ll curr_b_node=r[0];
            ll curr_r_node=r[0];

            for(ll i=0;b_dist>0;i++){
                if(b_dist%2==1){
                    curr_b_node=ancestors[i][curr_b_node];
                }
                b_dist/=2;
            }

            for(ll i=0;r_dist>0;i++){
                if(r_dist%2==1){
                    curr_r_node=ancestors[i][curr_r_node];
                }
                r_dist/=2;
            }

            if(below[curr_r_node]>above[ancestors[1][curr_r_node]]){
                cout<<below[ancestors[1][curr_r_node]]<<":"<<above[ancestors[1][curr_r_node]]<<endl;
                continue;
            }else{
                cout<<below[curr_r_node]<<":"<<above[curr_r_node]<<endl;
                continue;
            }
        }
        if(b_dist<depth[b[0]]-depth[lca] and r_dist<depth[r[0]]-depth[lca]){
            ll curr_b_node=b[0];
            ll curr_r_node=r[0];

            for(ll i=0;b_dist>0;i++){
                if(b_dist%2==1){
                    curr_b_node=ancestors[i][curr_b_node];
                }
                b_dist/=2;
            }

            for(ll i=0;r_dist>0;i++){
                if(r_dist%2==1){
                    curr_r_node=ancestors[i][curr_r_node];
                }
                r_dist/=2;
            }

            if(below[curr_r_node]>below[curr_b_node]){
                cout<<above[curr_b_node]<<":"<<below[curr_b_node]<<endl;
                continue;
            }else{
                cout<<below[curr_r_node]<<":"<<above[curr_r_node]<<endl;
                continue;
            }
        }

    }
    return 0;
    /*

7
1 3
1 4
4 6
1 2
2 5
6 7
3
1 3
1 5
1 1
1 2
1 1
1 5
5:1
    while(q--){
        ll from,to;
        cin>>from>>to;
        if(first_occ[from]>first_occ[to])
            swap(from,to);
        ll lca=query(0,euler_path.size()-1,first_occ[from],first_occ[to],1);
        cout<<lca<<endl;
        ll dist=depth[from]+depth[to]-2*depth[lca]+1;
        cout<<dist<<endl<<endl;
        if(dist==3){
            cout<<n<<":"<<0<<endl;
        }
        ll pr=from,pb=to;
        while(dist>4 and pr!=lca and pb!=lca){

        }
        ll r_size,b_size;
        cin>>r_size;
        if(is_star){
            ll state=0;
            for(ll i=0;i<r_size;i++){
                cin>>r[i];
                if(neighbors[r[i]]!=1){
                    state=1;
                }
            }
            cin>>b_size;
            for(ll i=0;i<b_size;i++){
                cin>>b[i];
                if(neighbors[b[i]]!=1){
                    state=2;
                }
            }
            if(state==0){
                cout<<n<<":0"<<endl;
            }
            if(state==1){
                cout<<n-b_size<<":"<<b_size<<endl;
            }
            if(state==2){
                cout<<r_size<<":"<<n-r_size<<endl;
            }
        }else{
            ll state_r=0,state_b=0;
            for(ll i=0;i<r_size;i++){
                cin>>r[i];
                if(neighbors[r[i]]==1){
                    state_r=1;
                }
            }
            cin>>b_size;
            for(ll i=0;i<b_size;i++){
                cin>>b[i];
                if(neighbors[b[i]]==1){
                    state_b=1;
                }
            }
            ll len=abs(depth[r[0]]-depth[b[0]])+1;
            ll new_depth_r;
            ll new_depth_b;
            if(depth[r[0]]<depth[b[0]]){
                new_depth_r=depth[r[0]];
                new_depth_b=depth[n]-depth[b[0]];
            }else{
                new_depth_r=depth[n]-depth[r[0]];
                new_depth_b=depth[b[0]];
            }
            if(len==2){
                cout<<new_depth_r+1<<":"<<new_depth_b+1<<endl;
                continue;
            }
            if(len==3){
                cout<<n<<":"<<0<<endl;
                continue;
            }
            if(len%2!=0){
                if(new_depth_r>=new_depth_b){
                    cout<<new_depth_r+len/2+2<<":"<<len/2-1+new_depth_b<<endl;
                }else{
                    cout<<new_depth_r+len/2<<":"<<new_depth_b+len/2+1<<endl;
                }
            }else{
                if(new_depth_r>new_depth_b){
                    cout<<new_depth_r+len/2+1<<":"<<len/2-1+new_depth_b<<endl;
                }else{
                    cout<<new_depth_r+len/2-1<<":"<<new_depth_b+len/2+1<<endl;
                }
            }
        }
        */
    return 0;
}
/*
6
1 2
1 3
1 4
1 5
1 6
3
1
1

2
2 3

2
2 4

1
1

1
2
3
3 4 5


7
1 2
2 3
3 4
4 5
5 6
6 7
13

1
7
1
6

1
7
1
5

1
7
1
4

1
7
1
3

1
7
1
2

1
7
1
1

1
2
1
3

1
2
1
4

1
2
1
5

1
2
1
6

1
2
1
7
*/
