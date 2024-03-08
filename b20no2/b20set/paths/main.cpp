#include <bits/stdc++.h>

using namespace std;

    bool visited[10001];
    int visit_count[10001],previous[10001];
    vector<int> neighbors[10001];
    queue<int> to_be_processed;

void bfs(int curr_node,int end_node){
    to_be_processed.pop();
    if(curr_node==end_node){
        for(int i=curr_node;i!=0;i=previous[i]){
            visit_count[i]++;
        }
        while(!to_be_processed.empty()){
            to_be_processed.pop();
        }
        return;
    }
    visited[curr_node]=true;
    for(int i=0;i<(int)neighbors[curr_node].size();i++){
        if(visited[neighbors[curr_node][i]]==false){
            previous[neighbors[curr_node][i]]=curr_node;
            to_be_processed.push(neighbors[curr_node][i]);
        }
    }
    while(!to_be_processed.empty()){
        bfs(to_be_processed.front(),end_node);
    }
}

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        int start_node,end_node;
        cin>>start_node>>end_node;
        to_be_processed.push(start_node);
        bfs(start_node,end_node);
        for(int j=0;j<n;j++){
            visited[i]=false;
        }
    }
    sort(visit_count,visit_count+10001);
    cout << visit_count[10000] << endl;
    return 0;
}
/*
5 6 2
1 3
3 5
1 2
2 4
4 5
2 5
1 5
2 4
*/
