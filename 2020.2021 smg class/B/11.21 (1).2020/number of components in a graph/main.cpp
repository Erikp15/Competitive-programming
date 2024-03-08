#include <bits/stdc++.h>

using namespace std;

    const int SIZE=100001;
    int node_comp_id[SIZE],component_count=0;
    vector<int> neighbors[SIZE];
    bool visited[SIZE];
    set<int> unvisited,next_node;
    int n,m,q;

void bfs(){
    for(int i=0;i<n;i++)unvisited.insert(i);
    while(!unvisited.empty()){
        next_node.insert(*unvisited.begin());
        cout<<*unvisited.begin()<<" "<<++component_count<<endl;
        while(!next_node.empty()){
            int curr_node=*next_node.begin();
            unvisited.erase(curr_node);
            for(auto i:neighbors[curr_node]){
                if(visited[i]==true)continue;
                //cout<<i<<endl;
                next_node.insert(i);
            }
            //cout<<"fuck"<<endl;
            node_comp_id[curr_node]=component_count;
            visited[curr_node]=true;
            next_node.erase(curr_node);
        }
    }
}

int main(){
    cin>>n>>m>>q;
    for(auto i=0;i<n;i++){
        node_comp_id[i]=i;
    }
    for(auto i=0;i<m;i++){
        int node_a,node_b; cin>>node_a>>node_b;
        neighbors[node_a].push_back(node_b);
        neighbors[node_b].push_back(node_a);
    }
    bfs();
    for(auto i=0;i<q;i++){
        int node_a,node_b; cin>>node_a>>node_b;
        cout<<node_comp_id[node_a]<<" "<<node_comp_id[node_b]<<endl;
    }
    return 0;
}
/*
5 4 2
0 1
2 0
1 2
3 4
*/
