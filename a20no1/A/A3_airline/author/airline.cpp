#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> edges[100001];
int depth[100001];
int bestChild[100001];
int secondBestChild[100001];
int ans[100001];

void calcDepth(int u, int p) {
    int ans = 0;
    for (int v: edges[u]) {
        if (v == p) continue;
        calcDepth(v, u);
        if (bestChild[u] == 0) bestChild[u]=v;
        else if (secondBestChild[u] == 0 || depth[secondBestChild[u]] < depth[v]) {
            secondBestChild[u] = v;
            if (depth[bestChild[u]] < depth[v]) swap(bestChild[u], secondBestChild[u]);
        }
        ans = max(ans, depth[v]+1);
    }
    depth[u]=ans;
}

void calcAns(int u, int p, int currMax) {
    ans[u] = max(depth[u], currMax);
    for (int v: edges[u]) {
        if (v == p) continue;

        int newMax = depth[u];
        if (secondBestChild[u] == 0) newMax = 0;
        else if (v==bestChild[u]) newMax = depth[secondBestChild[u]]+1;
        calcAns(v, u, max(currMax, newMax)+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    calcDepth(1, 0);
    calcAns(1, 0, 0);

    int best = 100000;
    for (int i = 1; i <= n; i++) best = min(best, ans[i]);
    vector<int> vertices;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == best) vertices.push_back(i);
    }

    cout << vertices.size() << endl;
    cout << vertices[0];
    for (int i = 1; i < vertices.size(); i++) {
        cout << " " << vertices[i];
    }
    cout << endl;

    return 0;
}
