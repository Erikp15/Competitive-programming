#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 1000;

int n, m,numberofcomponents=0,depthcheck=0;

vector<int> neighbors[MAX_N];
bool visited[MAX_N];

void dfs(int current) {
//    cout << "Visiting " << current <<" "<<depthcheck<< "\n";

    visited[current] = true;

    for(int i = 0; i < neighbors[current].size(); ++i) {
        if(!visited[neighbors[current][i]]) {
            depthcheck++;
            dfs(neighbors[current][i]);
        }else{

        }
    }
    if(depthcheck==1){
        numberofcomponents++;
        cout<<current<<endl;
    }else{
        cout<<current<<" ";
    }
    depthcheck--;
    return;
}

int main() {
    /// TODO: fast input

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int from, to;

        /// undirected
        cin >> from >> to;

        /// add from as a neighbor of to
        neighbors[from].push_back(to);

        /// add to as a neighbor of from
        neighbors[to].push_back(from);
    }
    cout<<"\n"<<"all closed components:"<<"\n";
    for(int i=0;i<n;i++){
        if(visited[i]==true){
            continue;
        }
        depthcheck++;
        dfs(i);
    }
/*
    for(int i = 0; i < n; ++i) {
        cout << i << ": ";

        for(int j = 0; j < neighbors[i].size(); ++j) {
            cout << neighbors[i][j] << " ";
        }

        cout << endl;
    }

    for(int i = 0; i < n; ++i) {
        cout << i << ": " << (visited[i] ? "true" : "false") << "\n";
    }
*/
    cout<<"\n"<<"number of closed components:"<<numberofcomponents<<endl;
    return 0;
}
