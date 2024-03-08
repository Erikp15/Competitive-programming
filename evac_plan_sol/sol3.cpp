#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int , int> ipair;
const int N = 5e5 + 5;
int n , m;
vector<pair<int , int> > adj[N];
int d[N] , vis[N];
int par[N] , sz[N];
int P[N][20] , mn[N][20] , depth[N];
struct Node{
    int u , v , w;
}E[N];
bool cmp(Node& X , Node& Y){
    return X.w < Y.w;
}
int Find(int x){
    if(par[x] == -1) return x;
    return par[x] = Find(par[x]);
}
int Un(int u , int v){
    u = Find(u);
    v = Find(v);
    if(u==v)return 0;
    if(sz[u] < sz[v])swap(u , v);
    par[v] = u;
    sz[u] += sz[v];
    return 1;
}
void dfs(int u , int p , int W){
    P[u][0] = p;
    mn[u][0] = W;
    for(int i = 1; i <= 17; ++i) P[u][i] = P[P[u][i - 1]][i - 1] , mn[u][i] = min(mn[u][i - 1] , mn[P[u][i - 1]][i - 1]);
    for(auto E : adj[u]){
        if(E.first==p)continue;
        depth[E.first] = depth[u] + 1;
        dfs(E.first , u , E.second);
    }
}
int LCA(int u , int v){
    if(depth[u] < depth[v])swap(u , v);
    int k = depth[u] - depth[v];
    int res = 1e18;
    for(int i = 18; ~i; --i){
        if(k>>i&1) res = min(res , mn[u][i]) , u = P[u][i];
    }
    if(u == v) return res;
    for(int i = 17; ~i; --i){
        if(P[u][i] != P[v][i]){
            res = min({res , mn[u][i] , mn[v][i]});
            u = P[u][i];
            v = P[v][i];
        }
    }
    return min({res , mn[u][0] , mn[v][0]});
}
 main (){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int u , v ,w;
    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u].emplace_back(v , w);
        adj[v].emplace_back(u , w);
        E[i].u = u , E[i].v = v , E[i].w = w;
    }
    priority_queue<pair<int,  int>> pq;
    for(int i =1; i <= n; ++i) d[i] = 1e18;
    int k;
    cin >> k;
    int a;
    for(int i = 0;i < k; ++i){
        cin >> a;
        d[a] = 0;
        pq.push({0 ,a});
    }
    while(pq.size()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto E : adj[u]){
            int v = E.first , w = E.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({-d[v] , v});
            }
        }
    }

    for(int i = 0; i < m; ++i) E[i].w = -min(d[E[i].u] , d[E[i].v]);
    sort(E , E + m ,cmp);
    memset(par ,-1 , sizeof(par));
    for(int i = 1; i <= n; ++i) adj[i].clear() , sz[i] =1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 20; ++j) mn[i][j] = 1e18;
    }
    for(int i = 0; i < m; ++i){
        int ux = E[i].u , vx = E[i].v , wx = -E[i].w;
        if(Un(ux , vx)){
            adj[ux].emplace_back(vx , wx);
            adj[vx].emplace_back(ux , wx);
        }
    }
    mn[1][0] = 1e18;
    dfs(1 , 0 ,1e18);
    int q;
    cin >> q;
    while(q--){
        int A , B;
        cin >> A >> B;
        cout << LCA(A , B) << endl;
    }

}
