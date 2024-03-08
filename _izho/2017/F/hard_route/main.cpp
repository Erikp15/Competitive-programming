#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e2+1;
vector<ll> adj[Size];
ll neighbors[Size];
ll visited[Size];
ll parent[Size];
pair<ll,ll> farthest_below[Size];
pair<ll,ll> farthest_above[Size];
pair<ll,ll> ans={0,1};
vector<pair<ll,ll>> branches;
ll n;

void calc_above(){
    queue<ll> to_process;
    for(ll i=0;i<n;i++){
        if(neighbors[i]==1){
            to_process.push(i);
            visited[i]=1;
        }
    }
    ll curr_node=0;
    while(!to_process.empty()){
        curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=2;
        for(auto next_node:adj[curr_node]){
            neighbors[next_node]--;
            if(visited[next_node]==0){
                if(neighbors[next_node]==1){
                    to_process.push(next_node);
                    visited[next_node]=1;
                }
            }
            if(visited[next_node]==2){
                if(farthest_below[curr_node].first<farthest_below[next_node].first+1){
                    farthest_below[curr_node]={farthest_below[next_node].first+1,farthest_below[next_node].second};
                }else{
                    if(farthest_below[curr_node].first==farthest_below[next_node].first){
                        farthest_below[curr_node].second+=farthest_below[next_node].second;
                    }
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        visited[i]=0;
    }
    parent[curr_node]=-1;
    visited[curr_node]=1;
    to_process.push(curr_node);
    while(!to_process.empty()){
        curr_node=to_process.front();
        to_process.pop();
        pair<ll,ll> farthest={0,1}, second_farthest={0,1};
        for(auto next_node:adj[curr_node]){
            if(!visited[next_node] and parent[curr_node]!=-1){
                if(farthest.first<farthest_above[curr_node].first+1){
                    farthest={farthest_above[curr_node].first+1,farthest_above[curr_node].second};
                }else{
                    if(second_farthest.first<farthest_above[curr_node].first+1){
                        second_farthest={farthest_above[curr_node].first+1,farthest_above[curr_node].second};
                    }
                }
            }else{
                if(farthest.first<farthest_below[next_node].first+2){
                    farthest={farthest_below[next_node].first+2,farthest_below[next_node].second};
                }else{
                    if(second_farthest.first<farthest_below[next_node].first+2){
                        second_farthest={farthest_below[next_node].first+2,farthest_below[next_node].second};
                    }
                }
            }
        }
        for(auto next_node:adj[curr_node]){
            if(!visited[next_node]){
                parent[next_node]=curr_node;
                to_process.push(next_node);
                visited[next_node]=true;
                if(farthest.first==farthest_below[next_node].first+2){
                    farthest_above[next_node]=second_farthest;
                }else{
                    farthest_above[next_node]=farthest;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll from,to;
        cin>>from>>to;
        from--; to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
        neighbors[from]++;
        neighbors[to]++;
        farthest_above[i]={0,1};
        farthest_below[i]={0,1};
    }
    farthest_above[n-1]={0,1};
    farthest_below[n-1]={0,1};
    calc_above();
    for(ll curr_node=0;curr_node<n;curr_node++){
        if(adj[curr_node].size()>2){
            pair<ll,ll> farthest={0,1}, second_farthest={0,1}, third_farthest={0,1};
            for(auto next_node:adj[curr_node]){
                if(next_node!=parent[curr_node]){
                    branches.push_back({farthest_below[next_node].first+1,farthest_below[next_node].second});
                }else{
                    branches.push_back({farthest_above[curr_node].first,farthest_above[curr_node].second});
                }
            }
            sort(branches.begin(),branches.end());
            reverse(branches.begin(),branches.end());
            farthest=branches[0];
            second_farthest=branches[1];
            third_farthest=branches[2];
            ll copys=0;
            for(ll i=3;i<branches.size() and third_farthest.first==branches[i].first;i++){
                copys+=branches[i].second;
            }
            ll curr_ans=farthest.first*(second_farthest.first+third_farthest.first);
            if(farthest.first==third_farthest.first){
                if(curr_ans>ans.first){
                    ans={curr_ans,(ll)3*copys*third_farthest.second*second_farthest.second*farthest.second};
                }else{
                    if(curr_ans==ans.first){
                        ans.second+=(ll)3*copys*third_farthest.second*second_farthest.second*farthest.second;
                    }
                }
            }else{
                if(second_farthest.first==third_farthest.first){
                    if(curr_ans>ans.first){
                        ans={curr_ans,copys*third_farthest.second*second_farthest.second*farthest.second};
                    }else{
                        if(curr_ans==ans.first){
                            ans.second+=copys*third_farthest.second*second_farthest.second*farthest.second;
                        }
                    }
                }else{
                    if(curr_ans>ans.first){
                        ans={curr_ans,(copys+third_farthest.second)*second_farthest.second*farthest.second};
                    }else{
                        if(curr_ans==ans.first){
                            ans.second+=(copys+third_farthest.second)*second_farthest.second*farthest.second;
                        }
                    }
                }
            }
            branches.clear();
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7
*/
