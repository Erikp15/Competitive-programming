#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll Size=2e5+1,INF=1e18,mod=1102024631;

vector<pair<ll,ll> > adj[Size];
ll pref_sum[Size],largest_subbranch[Size];
bool visited[Size];
ll n;
vector<ll> all_branch_costs;

ll b_search(ll l,ll r,ll v){
    ll mid=(l+r)/2;
    //cout<<"fowakjsdf"<<all_branch_costs[mid]<<" "<<all_branch_costs[mid+1]<<endl;
    if((all_branch_costs[mid]>=v and all_branch_costs[mid+1]<v) or l==r){
        return mid;
    }
    if(all_branch_costs[mid]<v){
        return b_search(l,mid,v);
    }else{
        return b_search(mid+1,r,v);
    }
}

void dfs_decomposition(ll prev_node,ll curr_node){
    visited[curr_node]=true;
    for(auto next_node:adj[curr_node]){
        if(next_node.first!=prev_node and !visited[next_node.first]){
            dfs_decomposition(curr_node,next_node.first);
            if(largest_subbranch[curr_node]<largest_subbranch[next_node.first]+next_node.second){
                if(largest_subbranch[curr_node]!=0)
                    all_branch_costs.push_back(largest_subbranch[curr_node]);
                largest_subbranch[curr_node]=largest_subbranch[next_node.first]+next_node.second;
            }else{
                all_branch_costs.push_back(largest_subbranch[next_node.first]+next_node.second);
            }
        }
    }
}

void reset_visited(){
    for(ll i=1;i<=n;i++){
        visited[i]=false;
    }
}

void reset(){
    for(ll i=0;i<=n;i++){
        adj[i].clear();
        visited[i]=false;
        largest_subbranch[i]=0;
    }
    all_branch_costs.clear();
}

void solve(){
    cin>>n;
    ll ans=0;
    for(ll i=0,from,to,weight;i<n-1;i++){
        cin>>from>>to>>weight;
        ans+=2*weight;
        adj[from].push_back({to,weight});
        adj[to].push_back({from,weight});
    }
    dfs_decomposition(-1,1);
    sort(all_branch_costs.rbegin(),all_branch_costs.rend());
    if(all_branch_costs.size()!=0){
        pref_sum[0]=all_branch_costs[0];
        for(ll i=1;i<all_branch_costs.size();i++){
            pref_sum[i]=pref_sum[i-1]+all_branch_costs[i];
        }
    }
/*
    for(auto itrv:all_branch_costs){
        cout<<itrv<<" ";
    }
    cout<<endl<<largest_subbranch[1]<<endl;
*/
    ll q=1;
    cin>>q;
    while(q--){
        ll cost;
        cin>>cost;
        if(all_branch_costs.size()==0 or cost>all_branch_costs[0]){
            cout<<ans-largest_subbranch[1]<<endl;
            continue;
        }
        ll loc=b_search(0,all_branch_costs.size()-1,cost);
        cout<<ans-largest_subbranch[1]-pref_sum[loc]+(loc+1)*cost<<endl;
    }
    reset();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
2
7
1 2 10
1 3 10
2 4 5
2 5 10000
3 6 1000
3 7 200
5
10000
1000
100
10
1

5
1 2 1
2 3 2
3 4 2
3 5 100
2
1
3
*/
