#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int n, m, start;
vector <int> nbsX[10000];
int minPath[10000];

void bfs(){
    queue<int> q;
    q.push(start);
    minPath[start] = 0;
    while(!q.empty()){
        int currentV = q.front();
        q.pop();
        for (int i=0; i < nbs[currentV].size(); i++) {
            int nextV = nbs[currentV][i];
            if (minPath[nextV] == -1) {
                minPath[nextV] = minPath[currentV] + 1;
                q.push(nextV);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> start;

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;

        --from;
        --to;

        nbs[from].push_back(to);
        nbs[to].push_back(from);
    }

    for (int i=0; i < n; i++) {
        minPath[i]=-1;
    }

    bfs();

    for (int i=0; i < n; i++) {
        cout << i << ": " << minPath[i] << endl;
    }

    return 0;
