#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    //sequence a, sequence k
    int a[n+1], k[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> k[i];

    int popCnt[1024];
    for (int i = 0; i < 1024; i++) popCnt[i] = __builtin_popcount(i);

    //dp[i][j][k] - index with longest chain given that
    //first 10 bits is i, last 10 bits is j, and there
    //must be k set bits in the first 10 bits
    static int dp[1024][1024][11];
    memset(dp, 0, sizeof(dp));
    //at index i what is the longest chain you can form
    int best[n+1];
    fill(best, best+n+1, 0);
    //at index i what is the first element in the longest
    //chain you can form so far
    int store[n+1];

    for (int i = 1; i <= n; i++){
        int right = a[i]&1023;
        int left = a[i]>>10;
        int idx = 0;
        for (int mask = 0; mask < 1024; mask++){
            int b = k[i]-popCnt[(right&mask)];
            if (b >= 0 and b <= 10)
                if (best[dp[left][mask][b]] > best[idx])
                    idx = dp[left][mask][b];
        }
        best[i] = best[idx]+1;
        store[i] = idx;
        for (int mask = 0; mask < 1024; mask++){
            int b = popCnt[(left&mask)];
            if (best[i] > best[dp[mask][right][b]])
                dp[mask][right][b] = i;
        }
    }
    int pos = max_element(best, best+n+1)-best;
    vector<int> res;
    while (pos != 0){
        res.push_back(pos);
        pos = store[pos];
    }
    reverse(res.begin(), res.end());
    cout<<res.size()<<endl;
    for (int i = 0; i < res.size(); i++) cout<<res[i]<<" ";
}
