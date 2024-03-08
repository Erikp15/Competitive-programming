#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e3+2,mod=1e9+7;
vector<ll> adj[Size];
ll occ[Size];
bool visited[Size];
ll n,m;

void solve(){
    cin>>n>>m;
    for(ll i=0;i<=n;i++){
        occ[i]=0;
        adj[i].clear();
    }
    for(ll i=0;i<m;i++){
        ll from,to;
        from--; to--;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(ll i=0;i<=n;i++){
        occ[adj[i].size()]++;
    }
    ll a=0;
    for(ll i=1;i<=n;i++){
        if(occ[i]!=0){
            a++;
        }
    }
    if(occ[n-1]){
        cout<<1<<" "<<n-2<<"\n";
        return;
    }
    if(n==5){
        cout<<2<<" "<<1<<"\n";
        return;
    }
    if(a==2){
        for(ll i=2;i<=n;i++){
            if(occ[i]!=0){
                cout<<i<<" "<<i-1<<"\n";
                return;
            }
        }
    }else{
        bool found=false;
        for(ll i=1;i<=n;i++){
            if(occ[i]==1){
                cout<<i<<" ";
            }
        }
        for(ll i=2;i<=n;i++){
            if(occ[i]>1){
                cout<<i-1<<"\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
3 2
1 2
2 3

1
7 6
1 2
1 3
2 4
3 5
1 6
6 7

1
10 9
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
*/
