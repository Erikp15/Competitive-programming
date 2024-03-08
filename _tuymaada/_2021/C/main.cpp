#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=1e6+1,mod=998244353;
    ll a[Size];
    vector<ll> adj[Size];
    bool visited[Size];

    ll bfs(ll node){
        visited[node]=true;
        ll sum=a[node];
        for(auto it:adj[node]){
            if(!visited[it]){
                sum+=dfs(it);
            }
        }
        return sum;
    }

    void solve(){
        ll n,best_city=0,best_ans=1e18;
        cin>>n;
        ll total=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            total+=a[i];
        }
        for(ll i=0;i<n-1;i++){
            ll a,b;
            cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(ll i=0;i<n;i++){
            visited[i]=true;
            ll total=a[i]*(a[i]-1)/2;
            for(auto it:adj[i]){
                ll p=dfs(it);
                total+=(p*(p-1)/2);
            }
            if(best_ans>total){
                best_ans=total;
                best_city=i;
            }
            for(ll j=0;j<n;j++)visited[j]=false;
        }
        cout<<best_city+1<<"\n"<<best_ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
4
2 2 2 2
1 2
3 2
4 2

2
4
*/
