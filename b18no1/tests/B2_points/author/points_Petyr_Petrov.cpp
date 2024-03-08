#include <iostream>
using namespace std;

int a[1000001];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0, x = 0; i < n; i++) {
        int w, h; cin >> w >> h;
        for (int j = 0; j <= w; j++) {
            if (x+j > 1000000) break;
            a[x+j] = max(a[x+j], h);
        }
        x += w;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if (y <= a[x]) ans++;
    }
    cout << ans << endl;
}
