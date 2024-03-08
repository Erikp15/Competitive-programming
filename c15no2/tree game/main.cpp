#include <iostream>
#include <vector>
using namespace std;

int counter=0;
vector<int> connected[1000];
pair <int, pair <int, pair <int, int> > > leaves[1000];

int bfs(int current,int optimalsofar,int depth){
    if(connected[current].empty()){
        return leaves[current];
    }
    for(int i=0;i<connected[current].size();i++){
        if(depth%2==0){
           if(formin>bfs(connected[current][i],optimalsofar,depth+1)){
                formin=bfs(connected[current][i],optimalsofar,depth+1);
           }
        }else{
           if(formax>bfs(connected[current][i],optimalsofar,depth+1)){
                formax=bfs(connected[current][i],optimalsofar,depth+1);
           }
        }
    }
    leaves[current]=depth,j
}
int main(){
    long long n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }
    optimal=bfs(1,0,1);
    cout << optimal << endl;
    return 0;
}
