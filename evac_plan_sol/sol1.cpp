#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i < y; i++)
#define pii pair<int, int>
#define f first
#define s second

struct Edge{ int a, b, w; };

const int mx = 1e5 + 5;

int n, m, k, q, dist[mx], par[mx], ans[mx];
vector<Edge> edg; vector<pii> adj[mx]; set<int> qrys[mx];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(dist, dist + n + 1, 2e9);

    cin >> k;
    FOR(i, 0, k){ int x; cin >> x; dist[x] = 0; pq.push({0, x}); }

    while (!pq.empty()){
        int cdist, cur; tie(cdist, cur) = pq.top(); pq.pop();
        if (dist[cur] != cdist) continue;
        for (pii nxt : adj[cur]){
            int D = cdist + nxt.s;
            if (D < dist[nxt.f]) dist[nxt.f] = D, pq.push({D, nxt.f});
        }
    }
}
int get(int i){
    return i == par[i] ? i : par[i] = get(par[i]);
}
void merge(int a, int b, int w){
    a = get(a); b = get(b); if (a == b) return;
    if (qrys[a].size() > qrys[b].size()) swap(qrys[a], qrys[b]);
    for (int x : qrys[a]){
        if (qrys[b].count(x)) ans[x] = w, qrys[b].erase(x);
        else qrys[b].insert(x);
    }
    par[a] = b;
}

int main(){
    cin >> n >> m;
    FOR(i, 1, m + 1){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
        edg.push_back({a, b, w});
    }
    dijkstra();

    cin >> q;
    FOR(i, 1, q + 1){
        int a, b; cin >> a >> b;
        qrys[a].insert(i); qrys[b].insert(i);
    }

    for (Edge &E : edg) E.w = min(dist[E.a], dist[E.b]);
    sort(edg.begin(), edg.end(), [](Edge a, Edge b){ return a.w > b.w; });

    FOR(i, 1, n + 1) par[i] = i;
    for (Edge E : edg) merge(E.a, E.b, E.w);

    FOR(i, 1, q + 1) cout<<ans[i]<<endl;
}
