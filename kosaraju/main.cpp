#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,m,timer=1,node_id=1,start_airport,tin[100001],tout[100001],comp_count=1,root[100001],indegree[100001];
    vector<ll> rev_adj[100001],adj[100001],cond_adj[100001],tout_ordered,curr_comp;
    bool visited[100001];

void tout_calc(ll curr_node){
    tin[curr_node]=timer;
    visited[curr_node]=true;
    for(ll i=0;i<adj[curr_node].size();i++){
        if(!visited[adj[curr_node][i]]){
            timer++;
            tout_calc(adj[curr_node][i]);
        }
    }
    tout[curr_node]=timer;
    timer++;
    tout_ordered.push_back(curr_node);
}

void comp_find(ll curr_node){
    visited[curr_node]=true;
    curr_comp.push_back(curr_node);
    for(ll i=0;i<rev_adj[curr_node].size();i++){
        if(!visited[rev_adj[curr_node][i]]){
            root[rev_adj[curr_node][i]]=root[curr_node];
            comp_find(rev_adj[curr_node][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    map<string,ll> air_2_id;
    for(ll i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        if(air_2_id.find(a)==air_2_id.end()){
            air_2_id[a]=node_id;
            node_id++;
        }
        if(air_2_id.find(b)==air_2_id.end()){
            air_2_id[b]=node_id;
            node_id++;
        }
        adj[air_2_id[a]].push_back(air_2_id[b]);
        rev_adj[air_2_id[b]].push_back(air_2_id[a]);
    }
    string a;
    cin>>a;
    if(air_2_id.find(a)==air_2_id.end()){
        air_2_id[a]=node_id;
        node_id++;
    }
    start_airport=air_2_id[a];
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            tout_calc(i);
        }
    }
    for(ll i=0;i<=n;i++){
        visited[i]=0;
    }
    for(ll i=tout_ordered.size()-1;i>=0;i--){
        ll curr_node=tout_ordered[i];
        if(!visited[curr_node]){
            root[curr_node]=curr_node;
            comp_find(curr_node);
            /*
            cout<<"component "<<comp_count<<endl;
            for(ll i=0;i<curr_comp.size();i++){
                cout<<curr_comp[i]<<endl;
            }
            */
            comp_count++;
            curr_comp.clear();
        }
    }
    cout<<endl;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<adj[i].size();j++){
            if(root[i]!=root[adj[i][j]]){
                cond_adj[root[i]].push_back(root[adj[i][j]]);
                indegree[root[adj[i][j]]]++;
            }
        }
    }
    ll res=0;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0 and root[i]==i){
            res++;
        }
    }
    if(indegree[root[start_airport]]==0)res--;
    cout<<res<<endl;
    return 0;
}
/*
8 9
JFK ORD
ORD LGA
LGA SUK
SUK JFK
LGA COC
COC KIL
KIL EEE
EEE DUC
DUC COC
COC

18 19
DSM ORD
ORD BGI
BGI LGA
SIN CDG
CDG SIN
CDG BUD
DEL DOH
DEL CDG
TLV DEL
EWR HND
HND ICN
HND JFK
ICN JFK
JFK LGA
EYW LHR
LHR SFO
SFO SAN
SFO DSM
SAN EYW
LGA
*/
