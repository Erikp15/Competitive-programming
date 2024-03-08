#include <bits/stdc++.h>

using namespace std;

int time_to_reach[1000000],n,p,a,b,r;
queue<int> visited;

void bfs(int n){
    visited.push(n%p);
    while(!visited.empty()){
        int current_n=visited.front();
        visited.pop();
        if (current_n==r&&time_to_reach[current_n]!=0)break;
        if(time_to_reach[(current_n+a)%p]==0){
            time_to_reach[(current_n+a)%p]=time_to_reach[current_n]+1;
            visited.push((current_n+a)%p);
        }
        if(time_to_reach[(current_n+b)%p]==0){
            time_to_reach[(current_n+b)%p]=time_to_reach[current_n]+1;
            visited.push((current_n+b)%p);
        }
    }

}

int main(){
    //memset ( time_to_reach, 0, sizeof(time_to_reach) );
    cin >> n >> p >> a >> b >> r;
    bfs(n);
    if (time_to_reach[r]!= 0){
        cout << time_to_reach[r] << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
/*
20 10
5 5 5

30 11
4 4 3
1
5
9
2
6
10
3
7
0
4
8
1
5
*/
