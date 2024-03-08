#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> edges[100001];

int depth(int u, int p) {
    int ans = 0;
    for (int v: edges[u]) {
        if (v == p) continue;
        ans = max(ans, depth(v, u)+1);
    }
    return ans;
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

    int ans = depth(1, 0);
    vector<int> vertices(1, 1);
    for (int i = 2; i <= n; i++) {
        int curr = depth(i, 0);
        if (curr < ans) {
            ans = curr;
            vertices.clear();
            vertices.push_back(i);
        } else if (curr == ans) {
            vertices.push_back(i);
        }
    }

    cout << vertices.size() << endl;
    cout << vertices[0];
    for (int i = 1; i < vertices.size(); i++) {
        cout << " " << vertices[i];
    }
    cout << endl;

    return 0;
}

/*
9
1 9
9 7
7 6
6 5
5 2
2 8
2 3
3 4
*/
