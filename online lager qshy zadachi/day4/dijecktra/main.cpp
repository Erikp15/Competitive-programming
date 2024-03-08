#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// to do:
//std::numeric_limits<T>::has_infinity == true;

struct node{
    int number;
    int length;
    node(int init_number,int init_length){
        number=init_number;
        length=init_length;
    }
};

bool operator<(node a,node b){
    return a.length>b.length;
}

vector<int> connections[1000],cost[1000];
bool isvisited[1000];
int n;
priority_queue<node> allroads;


void dijkstra(int start,int goal){
    for(int i=1;i<=n;){
        allroads.push( new node(i,100000) );
    }
    node v;
    v.number=start;
    v.length=0;
    while(!allroads.empty()){
        node curr=allroads.top();
        allroads.pop();
        for(int i=0;i<connections[curr.number].size();i++){
            if(isvisited[connections[curr.number][i]]==false){
                if(cost[curr.number][i]+curr.length<shortestpathsofar[connections[curr.number][i]]){
                    allroads.push(connections[curr.number][i],cost[curr.number][i]+curr.length);
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
        cost[b].push_back(a);
    }
    int k;
    cin>>k;
    int q;
    cin>>q;
    dijecktra(k,q);
    cout<<allroads.top().length<< endl;
    return 0;
}
