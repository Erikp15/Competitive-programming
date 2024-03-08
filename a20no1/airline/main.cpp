#include <bits/stdc++.h>

using namespace std;

    const int MAX_SIZE=100001;
    int node_answer[MAX_SIZE];
    set<int> neighbors[MAX_SIZE];
    queue<int> process_order;
    bool visited[MAX_SIZE];

void bfs(){
    while(!process_order.empty()){
        int curr_node=process_order.front();
        process_order.pop();
        visited[curr_node]=true;
        for(set<int>::iterator it=neighbors[curr_node].begin();it!=neighbors[curr_node].end();++it){
            int curr_neighbor=*it;
            if(visited[curr_neighbor]==false and neighbors[curr_neighbor].size()<=2){
                visited[curr_neighbor]=true;
                process_order.push(curr_neighbor);
                node_answer[curr_neighbor]=node_answer[curr_node]+1;
            }
            neighbors[curr_neighbor].erase(curr_node);
        }
    }
}
int main(){
    int n,max_count=0,answer_count=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        neighbors[a].insert(b);
        neighbors[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        if(neighbors[i].size()==1)process_order.push(i);
    }
    bfs();
    for(int i=1;i<=n;i++){
        max_count=max(max_count,node_answer[i]);
    }
    for(int i=1;i<=n;i++){
        if(node_answer[i]==max_count){
            answer_count++;
        }
    }
    cout<<answer_count<<endl;
    for(int i=1;i<=n;i++){
        if(node_answer[i]==max_count){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
/*
7
4 3
2 3
6 2
2 5
1 5
1 7
*/
