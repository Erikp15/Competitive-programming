#include<bits/stdc++.h>
using namespace std;

bool table[1001][1001];

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 500; y1 += 500; x2 += 500; y2 += 500;
        int xdiff = x2-x1;
        int ydiff = y2-y1;
        int gcd = __gcd(abs(xdiff), abs(ydiff));
        xdiff /= gcd;
        ydiff /= gcd;

        while (true) {
            if (!table[x1][y1]) {
                ans++;
                table[x1][y1]=true;
            }
            if (x1==x2 && y1==y2) break;
            x1 += xdiff;
            y1 += ydiff;
        }
    }
    cout << ans << endl;

    return 0;
}
