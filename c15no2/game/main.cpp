#include <iostream>
#include <vector>
using namespace std;

vector<int> connections[20001],cost[20001],reward[20001];
long big=-999999;

int thenumforcost(int a,int n){
    for(int i=0;i<cost[a].size();i++){
        if(cost[a][i]==n){return n;}
    }
    cout<<"ERROR";
    return 0;
}
int thenumforreward(int a,int n){
    for(int i=0;i<reward[a].size();i++){
        if(reward[a][i]==n){return i;}
    }
    cout<<"ERROR";
    return 0;
}

void bfs(int current,int points,int energy){
    if(big<points){big=points;}
    for(long i=0;i<connections[current].size();i++){
        if(energy-cost[connections[current][i]][thenumforcost(connections[current][i],i)]>energy){continue;}
        bfs(connections[current][i],points+reward[connections[current][i]][thenumforreward(connections[current][i],i)],energy-cost[connections[current][i]][thenumforcost(connections[current][i],i)]);
    }
    return;
}

int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    for(long long i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        connections[a].push_back(b);
        cost[a].push_back(b);
        reward[a].push_back(b);
    }
    bfs(1,0,k);
    cout << big << endl;
    return 0;
}
