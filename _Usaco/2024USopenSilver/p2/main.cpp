#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=2e2+1;

vector<pair<ll,ll> > adj[Size];
pair<ll,ll> posts[Size];
map<ll,set<pair<ll,ll>> > x2point;
map<ll,set<pair<ll,ll>> > y2invertedpoint;
map<pair<ll,ll>,ll> point2id;
map<ll,ll> id2seq;
ll pref_sum[Size];
bool visited[Size];

void dfs(ll prev_node, ll curr_node,ll value,ll seq){
    id2seq[curr_node]=seq;
    visited[curr_node]=true;
    pref_sum[seq]=value;
    for(auto next_node:adj[curr_node]){
        if(next_node.first!=prev_node){
            if(visited[next_node.first]){
                if(id2seq[next_node.first]<seq){
                    //cout<<curr_node<<" "<<next_node.first<<" "<<value+next_node.second<<endl;
                    pref_sum[seq+1]=pref_sum[seq]+next_node.second;
                }
            }else{
                dfs(curr_node,next_node.first,value+next_node.second,seq+1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,p;
    cin>>n>>p;
    for(ll i=0;i<p;i++){
        cin>>posts[i].first>>posts[i].second;
        point2id[{posts[i].first,posts[i].second}]=i;
        if(x2point.find(posts[i].first)==x2point.end()){
            set<pair<ll,ll>> tmp;
            tmp.insert(posts[i]);
            x2point[posts[i].first]=tmp;
        }else{
            x2point[posts[i].first].insert(posts[i]);
        }
        if(y2invertedpoint.find(posts[i].second)==y2invertedpoint.end()){
            set<pair<ll,ll>> tmp;
            tmp.insert({posts[i].second,posts[i].first});
            y2invertedpoint[posts[i].second]=tmp;
        }else{
            y2invertedpoint[posts[i].second].insert({posts[i].second,posts[i].first});
        }
    }
/*
    for(auto itrv:x2point){
        cout<<itrv.first<<endl;
        for(auto itrv2:itrv.second){
            cout<<itrv2.first<<" "<<itrv2.second<<endl;
        }
    }
    cout<<endl;
    for(auto itrv:y2invertedpoint){
        cout<<itrv.first<<endl;
        for(auto itrv2:itrv.second){
            cout<<itrv2.second<<" "<<itrv2.first<<endl;
        }
    }

    cout<<endl;
    */
    for(auto itrv:x2point){
        ll prev=-1;
        for(auto itrv2:itrv.second){
            ll next_point=point2id[itrv2];
            if(prev==-1){
                prev=next_point;
            }else{
                //cout<<prev<<" "<<next_point<<endl;
                adj[prev].push_back({next_point,abs(itrv2.second-posts[prev].second)});
                adj[next_point].push_back({prev,abs(itrv2.second-posts[prev].second)});
                prev=-1;
            }
        }
    }
    for(auto itrv:y2invertedpoint){
        ll prev=-1;
        for(auto itrv2:itrv.second){
            ll next_point=point2id[{itrv2.second,itrv2.first}];
            if(prev==-1){
                prev=next_point;
            }else{
                //cout<<next_point<<endl;
                adj[prev].push_back({next_point,abs(itrv2.second-posts[prev].second)});
                adj[next_point].push_back({prev,abs(itrv2.second-posts[prev].second)});
                prev=-1;
            }
        }
    }
    dfs(-1,0,0,0);
    /*
    for(ll i=0;i<=n;i++){
        cout<<pref_sum[i]<<" ";
    }
    cout<<endl;
    */
    for(ll t=0;t<n;t++){
        pair<ll,ll> start_point, end_point;
        cin>>start_point.first>>start_point.second>>end_point.first>>end_point.second;
        if(x2point.find(start_point.first)!=x2point.end()){

        }
    }
    return 0;
}
/*
5 4
3 1
1 5
3 5
1 1
*/
