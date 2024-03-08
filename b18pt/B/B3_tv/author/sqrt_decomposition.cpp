#include <iostream>
#include <set>

using namespace std;

const int BUCKETS = 710;

int elements[1000000];
int sums[BUCKETS];
int signs[BUCKETS];
int next1[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    string s; cin >> s;

    int last = s.size();
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] != 'o') last = i;
        next1[i] = last;
    }
    next1[s.size()] = s.size();

	last = 0;
    for (int i = 0; i < s.size(); i++) {
        int current = -last;
        if (s[i] == '+') current = 1;
        if (s[i] == '-') current = -1;
        elements[i] = current;
        last = current;
    }

    int sum = 1;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < BUCKETS; j++) {
            sums[i] += elements[BUCKETS*i+j];
        }
        signs[i] = 1;
        sum += sums[i];
    }

    while (q-- > 0) {
        int a, b; cin >> a >> b; a--; b--;
        a = next1[a];
        b = next1[b+1]-1;
        if (a <= b) {
            int s = a/BUCKETS;
            int e = b/BUCKETS;
            if (s == e) {
                for (int i = a; i <= b; i++) {
                    elements[i] = -elements[i];
                    sums[s] += 2*elements[i];
                    sum += 2*signs[s]*elements[i];
                }
            } else {
                for (int i = a; i < (s+1)*BUCKETS; i++) {
                    elements[i] = -elements[i];
                    sums[s] += 2*elements[i];
                    sum += 2*signs[s]*elements[i];
                }
                for (int i = s + 1; i < e; i++) {
                    signs[i] = -signs[i];
                    sum += 2*sums[i]*signs[i];
                }
                for (int i = e*BUCKETS; i <= b; i++) {
                    elements[i] = -elements[i];
                    sums[e] += 2*elements[i];
                    sum += 2*signs[e]*elements[i];
                }
            }
        }
        sum %= n;

        if (sum <= 0) sum += n;
        cout << sum << endl;
    }
}
