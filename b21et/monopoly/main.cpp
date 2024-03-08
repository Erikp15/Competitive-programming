#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e6+1;
bool visited[Size],is_con[Size];
vector<pair<ll,ll>> adj[Size],rev_adj[Size];
queue<ll> to_process;
string ans;

void bfs(ll start_node){
    to_process.push(start_node);
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=true;
        for(auto itr:adj[curr_node]){
            if(!is_con[itr.second]){
                ans[itr.second]='1';
                is_con[itr.second]=true;
            }
            if(!visited[itr.first]){
                visited[itr.first]=true;
                to_process.push(itr.first);
            }
        }
        for(auto itr:rev_adj[curr_node]){
            is_con[itr.second]=true;
        }
    }
}

bool dfs(ll node){
    visited[node]=true;
    for(auto itr:adj[node]){
        if(ans[itr.second]=='1')continue;
        if(!visited[itr.first]){
            if(dfs(itr.first)==false){
                return 0;
            }
        }else{
            return 0;
        }
    }
    for(auto itr:rev_adj[node]){
        if(ans[itr.second]=='0')continue;
        if(!visited[itr.first]){
            if(dfs(itr.first)==false){
                return 0;
            }
        }else{
            return 0;
        }
    }
    return 1;
}

bool check(ll start_node,ll n){
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            bool res=dfs(i);
            if(!res)return 0;
        }
    }
    return 1;
}

string find_reverse(ll n, ll m, ll connections[][2]){
    while(ans.size()<m){
        ans+='0';
    }
    for(ll i=0;i<m;i++){
        adj[connections[i][0]].push_back({connections[i][1],i});
        rev_adj[connections[i][1]].push_back({connections[i][0],i});
    }
    //for(ll i=1;i<=n;i++){
        bfs(n/2);
        /*
        for(ll j=1;j<=n;j++){
            visited[j]=false;
        }
        if(check(i,n)){
            return ans;
        }
        for(ll j=1;j<=n;j++){
            visited[j]=false;
        }
        ans="";
        while(ans.size()<m){
            ans+='0';
        }
    }
    ans="";
    */
    return ans;
}
/*
int main(){
    ll n,m;
    cin>>n>>m;
    ll a[1000][2];
    for(ll i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
    }
    cout<<find_reverse(n,m,a)<<endl;
    return 0;
}
/*
4 6
1 2
2 3
3 4
1 4
1 3
4 2

5 10
1 2
2 3
3 4
4 5
5 1
1 3
1 4
2 4
2 5
3 5

3 2
1 2
3 1
*/
