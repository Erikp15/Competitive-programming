#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestto[100];
bool havebeento[100];
vector<int> neighbors[100];


void dfs(int start){

}
int main(){
    int n,m,k,Q;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    bfs();
    return 0;
}
