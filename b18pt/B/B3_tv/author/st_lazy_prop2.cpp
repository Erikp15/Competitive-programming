#include <iostream>
#include <set>

using namespace std;

int segmentTree[1<<21];
int sign[1<<21];
int next1[1<<20];
int val[1<<20];

void build(int node, int left, int right) {
    if (left == right) {
        segmentTree[node] = val[left-1];
        return;
    }

    int mid = (left + right) / 2;
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);
    segmentTree[node] = segmentTree[2*node] + segmentTree[2*node+1];
}

void lazyUpdate(int node, int left, int right, int start, int end) {
	if (start > end) return;
	if (right < start || left > end) return;
	if (start <= left && right <= end) {
		sign[node] = -sign[node];
		return;
	}
	int mid = (left + right) / 2;

	if (sign[node] == -1) {
		lazyUpdate(2*node, left, mid, left, right);
		lazyUpdate(2*node+1, mid+1, right, left, right);
		sign[node] = 1;
	}

	lazyUpdate(2*node, left, mid, start, end);
	lazyUpdate(2*node+1, mid+1, right, start, end);
	segmentTree[node] = sign[2*node] * segmentTree[2*node] + sign[2*node+1]*segmentTree[2*node+1];
}

int sum() {
	return sign[1] * segmentTree[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    string s; cin >> s;

    int last = s.size();
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] != 'o') last = i;
        next1[i+1] = last+1;
    }
    next1[s.size()+1] = s.size()+1;

	fill_n(sign, 1<<21, 1);

    last = 0;
    for (int i = 0; i < s.size(); i++) {
        int current = -last;
        if (s[i] == '+') current = 1;
        if (s[i] == '-') current = -1;
        val[i] = current;
        last = current;
    }

    build(1, 1, s.size());

    while (q-- > 0) {
        int a, b; cin >> a >> b;
        a = next1[a];
        b = next1[b+1]-1;
        lazyUpdate(1, 1, s.size(), a, b);
        int ans = (1 + sum())%n;
        if (ans <= 0) ans += n;
        cout << ans << endl;
    }
}

