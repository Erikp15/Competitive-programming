#include <iostream>
using namespace std;

const int MAXN = 1000001;
int a[MAXN];
int b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    long long n, m, t, l;
    cin >> n >> m >> t >> l;

	for (int i = 0; i < n; i++) {
        int next; cin >> next;
        a[next]++;
	}
	for (int i = 0; i <= n; i++) {
        b[a[i]]++;
	}

	long long time = 0;
	long long current = n;
	for (int i = 0; ; i++) {
		while (b[current] == 0) current--;
		if (current == 0) break;

		b[current]--;
		long long currentTime = current*(t+l) + (i/m)*t;
		time = max(time, currentTime);
	}

	cout << time << endl;
}
