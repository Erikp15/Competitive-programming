#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int offices[1001];
unordered_map<int, int> pows;
vector<pair<int, int>> edges[33];

int p[1000];
int w[1000];

int root(int u) {
    return p[u] = (u==p[u]?u:root(p[u]));
}

bool connected(int u, int v) {
    return root(u) == root(v);
}

bool connect(int u, int v) {
    int rU = root(u);
    int rV = root(v);
    if (w[rU] < w[rV]) {
        swap(rU, rV);
    }
    p[rV] = p[rU];
    w[rU] += w[rV];
}

int main() {
    int n, k;
    cin >> n >> k;

    int categories;
    for (int i = 0; i < n; i++) {
        int c, current, all = 0;
        cin >> c;
        while (c--) {
            cin >> current; current--;
            all |= (1 << current);
        }
        offices[i] = all;
    }

    pows[0] = k;
    for (int i = 0; i < 32; i++) pows[1<<i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = offices[i] & offices[j];
            x = x&(-x);
            edges[pows[x]].push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < n; i++) p[i] = i, w[i] = 1;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (auto p: edges[i]) {
            if(connected(p.first, p.second)) continue;

            ans += (i+1);
            connect(p.first, p.second);
        }
    }

    cout << ans << endl;

    return 0;
}
