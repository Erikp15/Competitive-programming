#include <iostream>
#include <vector>
using namespace std;
vector<int> connections[1001],cost[1001];
bool isvisited[1001];
int shortestpathsofar[1001],n;
int previous[1001];


void dijkstra(int curr,int theend){
    for(int i=0;i<=n;i++){
        shortestpathsofar[i]=100000;
    }
    shortestpathsofar[curr]=0;
    while(isvisited[theend]!=true){
        int shortestinhere=100000;
        for(int i=1;i<=n;i++){
            if(shortestpathsofar[i]<shortestinhere and isvisited[i]==false){
                shortestinhere=shortestpathsofar[i];
                curr=i;
            }
        }
        isvisited[curr]=true;
        for(int i=0;i<connections[curr].size();i++){
            if(cost[curr][i]+shortestpathsofar[curr]<shortestpathsofar[connections[curr][i]]){
                 if(isvisited[connections[curr][i]]!=true){
                    shortestpathsofar[connections[curr][i]]=cost[curr][i]+shortestpathsofar[curr];
                    previous[connections[curr][i]]=curr;
                }
            }
        }
    }
}
int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        connections[a].push_back(b);
        connections[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    int k;
    cin>>k;
    int q;
    cin>>q;
    dijkstra(k,q);
    cout << shortestpathsofar[q] << endl;
    cout<<q<<" ";
    for(int i=q;;i=i){
        if(previous[i]==0){break;}
        cout<<previous[i]<<" ";
        i=previous[i];
    }
    return 0;
}

/*
5 4
1 3 2
1 2 1
2 4 7
3 4 5
1 4
*/
