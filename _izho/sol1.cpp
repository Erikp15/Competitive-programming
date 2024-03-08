#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, B = 1<<10;

int n, a[MAXN], k[MAXN], p[MAXN], dp[21][B][B], g[21][B][B];
array<int, 2> res;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];

	for(int i=0; i<n; ++i){
		cin >> k[i];
		int curr = 1, req, x = (a[i] & (B-1)), r = (a[i] ^ x) >> 10;
		p[i] = -1;

		for(int l=0; l<B; ++l){
			req = k[i] - __builtin_popcount(l & x);
			if(0 <= req && curr <= dp[req][r][l]){
				curr = dp[req][r][l] + 1;
				p[i] = g[req][r][l];
			}
		}

		for(int j=0; j<B; ++j){
			req = __builtin_popcount(j&r);
			if(dp[req][j][x] < curr){
				dp[req][j][x] = curr;
				g[req][j][x] = i;
			}
		}

		res = max(res, {curr, i});
	}
	cout << res[0] << '\n';
	int ans[res[0]];
	for(int i=0; i<res[0]; ++i){
		ans[i] = res[1];
		res[1] = p[res[1]];
	}
	for(int i=res[0]; --i>=0; ) cout << ans[i]+1 << ' ';
}
