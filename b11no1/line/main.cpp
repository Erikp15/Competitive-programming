#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class point{
    public:
        ll x,y;
        ll distance(const point& a)const{
            return abs(x-a.x)+abs(y-a.y);
        }
};

    ll n;
    point all_points[11];
    bool visited[11];
    ll neighbors_count[11];

ll bfs(ll start){
    vector<ll> nodes_so_far;
    nodes_so_far.push_back(start);
    ll mstree=0;
    while(nodes_so_far.size()<n){
        ll closest_node=10000,previous_node=0,closest_node_index=0;
        visited[nodes_so_far[nodes_so_far.size()-1]]=true;
        for(ll i=0;i<(ll)nodes_so_far.size();i++){
            if(neighbors_count[nodes_so_far[i]]>1)continue;
            for(ll j=0;j<n;j++){
                if(visited[j]==true)continue;
                if(closest_node>all_points[nodes_so_far[i]].distance(all_points[j])){
                    //cout<<nodes_so_far[i]<<" "<<j<<endl;
                    closest_node=all_points[nodes_so_far[i]].distance(all_points[j]);
                    closest_node_index=j;
                    previous_node=nodes_so_far[i];
                }
            }
        }
        mstree+=closest_node;
        nodes_so_far.push_back(closest_node_index);
        neighbors_count[closest_node_index]++;
        neighbors_count[previous_node]++;
    }
    return mstree;
}
int main(){
    ll best=10000;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>all_points[i].x>>all_points[i].y;
    }
    best=bfs(0);
    cout<<best<<endl;
    return 0;
}
