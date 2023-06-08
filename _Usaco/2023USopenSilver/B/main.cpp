#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e6+1;
ll n,c;
string a[Size];
ll xored[Size];
ll dist[Size];
ll ans[Size];
bool exists[Size];
bool visited[Size];

void bfs(ll start_node){
    queue<ll> to_process;
    to_process.push(start_node);
    while(!to_process.empty()){
        ll curr_node=to_process.front();
        to_process.pop();
        visited[curr_node]=true;
        for(ll i=0;i<c;i++){
            ll next_node=curr_node^(1<<i);
            if(!visited[next_node]){
                dist[next_node]=dist[curr_node]+1;
                visited[curr_node]=true;
                to_process.push(next_node);
            }
        }
    }
}

void solve(){
    cin>>c>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        for(ll j=0;j<c;j++){
            xored[i]=(xored[i]<<1);
            if(a[i][j]=='G'){
                xored[i]++;
            }
        }
        exists[xored[i]]=true;
    }

    for(ll i=0;i<(1<<c);i++){
        if(exists[(1<<c)-1-i]){
            ans[i]=c;
        }else{
            bfs(i);
            ll c_ans=0;
            for(ll j=0;j<(1<<c);j++){
                if(i!=j and exists[j]){
                    c_ans=max(c_ans,dist[j]);
                }
                visited[j]=0;
                dist[j]=0;
            }
            ans[i]=c_ans;
        }
    }
    for(ll i=0;i<n;i++){
        cout<<ans[xored[i]]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
3 6
HGH
HGG
GHH
GHG
GGH
GGG

7 2
GHHHHHH
GGGGHHH
*/
