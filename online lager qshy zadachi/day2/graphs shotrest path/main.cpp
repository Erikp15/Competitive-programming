#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestto[100];
bool havebeento[100];
vector<int> neighbors[100];

void bfs(int start,int depth){
    havebeento[start]=true;
    for(int i=0;i<neighbors[start].size();i++){
        if(havebeento[neighbors[start][i]]==false){

            havebeento[start]=true;
            bfs(neighbors[start][i]);
        }
    }
    return;
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
    cin>>k>>Q;
    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        bfs(k);
        cout<<shortestto[q]<<"\n";
        for(int j=0;j<n+1;j++){
            havebeento[i]=false;
            shortestto[i]=0;
        }
    }
    return 0;
}
