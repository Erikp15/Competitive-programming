#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;


ll n,p[Size],edge_c[Size],max1[Size],max2[Size],ans_c[Size],ans=0,total=0;
vector<pair<ll,ll> > adj[Size];
set<pair<ll,ll> > dist;
set<ll> best;
unordered_map<ll,ll> id_2_d;
bool visited[Size];

void find_loop(){
    queue<ll> to_process;
    for(ll i=1;i<=n;i++){
        if(edge_c[i]==1)
            to_process.push(i);
    }
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=true;
        for(ll i=0;i<adj[curr_node].size();i++){
            pair<ll,ll> next_node=adj[curr_node][i];
            if(!visited[next_node.first]){
                edge_c[next_node.first]--;
                if(edge_c[next_node.first]==1){
                    to_process.push(next_node.first);
                }
            }else{
                if(max1[next_node.first]+next_node.second>=max1[curr_node]){
                    max2[curr_node]=max1[curr_node];
                    max1[curr_node]=max1[next_node.first]+next_node.second;
                }else if(max1[next_node.first]+next_node.second>max2[curr_node]){
                    max2[curr_node]=max1[next_node.first]+next_node.second;
                }
            }
        }
        ans=max(ans,max1[curr_node]+max2[curr_node]);
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            for(ll j=0;j<adj[i].size();j++){
                pair<ll,ll> next=adj[i][j];
                if(visited[next.first]){
                    if(max1[next.first]+next.second>=max1[i]){
                        max2[i]=max1[i];
                        max1[i]=max1[next.first]+next.second;
                    }else if(max1[next.first]+next.second>max2[i]){
                        max2[i]=max1[next.first]+next.second;
                    }
                }
            }
        }
    }
}

ll find_tot(ll start,ll prev,ll curr,ll tot){
    for(ll i=0;i<adj[curr].size();i++){
        if(!visited[adj[curr][i].first] and adj[curr][i].first!=prev and adj[curr][i].first!=start){
            return find_tot(start,curr,adj[curr][i].first,tot+adj[curr][i].second);
        }
    }
    return tot;
}

void go_through(ll start,ll prev,ll curr,ll tot){
    if(tot>total/2)
        return;
    dist.insert({tot,curr});
    best.insert(max1[curr]+tot);
    id_2_d[curr]=max1[curr]+tot;
    for(ll i=0;i<adj[curr].size();i++){
        if(!visited[adj[curr][i].first] and adj[curr][i].first!=prev and adj[curr][i].first!=start){
            go_through(start,curr,adj[curr][i].first,tot+adj[curr][i].second);
        }
    }
}

void solve(ll start,ll prev,ll curr,ll comp){
    for(auto itrv=dist.begin();itrv!=dist.end();itrv=dist.begin()){
        if((*itrv).first+comp>total/2){
            best.erase(id_2_d[(*itrv).second]);
            dist.erase(*itrv);
        }else{
            break;
        }
    }
    for(ll i=0;i<adj[curr].size();i++){
        if(adj[curr][i].first==prev){
            if(adj[curr][i].second>total/2)
                break;
            best.insert(max1[prev]+comp-adj[curr][i].second);
            id_2_d[prev]=max1[prev]+comp-adj[curr][i].second;
            dist.insert({-adj[curr][i].second,prev});
        }
    }
    if(best.size()!=0)
        ans=max(ans,max1[curr]+*best.rbegin()+comp);
    for(ll i=0;i<adj[curr].size();i++){
        if(!visited[adj[curr][i].first] and adj[curr][i].first!=prev and adj[curr][i].first!=start){
            solve(start,curr,adj[curr][i].first,comp+adj[curr][i].second);
        }
    }
}


void solve_loop(){
    ll start=0;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            start=i;
            break;
        }
    }
    if(!start)
        return;
    pair<ll,ll> next={0,0},after;
    for(ll i=0;i<adj[start].size();i++){
        if(!visited[adj[start][i].first]){
            if(next.first){
                after=adj[start][i];
            }else{
                next=adj[start][i];
            }
        }
    }
    total=find_tot(start,start,next.first,next.second);
    total+=after.second;
    go_through(start,start,next.first,next.second);
    if(best.size()!=0)
        ans=max(ans,max1[start]+*best.rbegin());
    solve(start,start,after.first,after.second);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }
    for(ll i=1;i<=n;i++){
        ll w;
        cin>>w;
        if(p[i]!=i){
            adj[i].push_back({p[i],w});
            adj[p[i]].push_back({i,w});
            edge_c[i]++;
            edge_c[p[i]]++;
        }
    }
    find_loop();
    solve_loop();
    cout<<ans<<endl;
    return 0;
}
