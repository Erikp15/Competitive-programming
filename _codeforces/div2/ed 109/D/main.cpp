#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=5001;
    ll n,total_time=0,taken[Size];

    void bfs(ll start_node){
        bool visited[Size];
        for(ll i=0;i<n;i++)visited[i]=false;
        queue<ll>to_pro;
        to_pro.push(start_node);
        while(!to_pro.empty()){
            ll curr_node=to_pro.front();
            to_pro.pop();
            visited[curr_node]=true;
            if(curr_node!=n-1){
                if(taken[curr_node+1]==0){
                    taken[curr_node+1]=2;
                    total_time+=abs(start_node-(curr_node+1));
                    return;
                }else{
                    if(!visited[curr_node+1]){
                        to_pro.push(curr_node+1);
                    }
                }
            }
            if(curr_node!=0){
                if(taken[curr_node-1]==0){
                    taken[curr_node-1]=2;
                    total_time+=abs(start_node-(curr_node-1));
                    return;
                }else{
                    if(!visited[curr_node-1]){
                        to_pro.push(curr_node-1);
                    }
                }
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>taken[i];
    }
    for(ll i=0;i<n;i++){
        if(taken[i]==1){
            bfs(i);
        }
    }
    cout<<total_time<<endl;
    return 0;
}
/*
4
0 1 0 1
*/
