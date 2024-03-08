#include <iostream>
using namespace std;

const int MOD = 1001027;

bool open[2000];
int dp[2000][1001];

int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int c; cin >> c;
        open[c]=1;
    }

    dp[0][0] = 1;
    for (int len = 1; len <= 2*n; len++) {
        if (!open[len]) dp[len][0] = dp[len-1][1];
        for (int diff = 1; diff <= n; diff++) {
            dp[len][diff] = dp[len-1][diff-1];
            if (!open[len]) dp[len][diff] += dp[len-1][diff+1];
            if (dp[len][diff] > MOD) dp[len][diff] %= MOD;
        }
    }

    cout << dp[2*n][0];
    return 0;
}
