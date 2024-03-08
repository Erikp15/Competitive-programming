#include <iostream>
using namespace std;

void solve() {
    string s; cin >> s;
    s += "+";
    int result = 0;
    int current = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*' || s[i] == '+') continue;
        if (s[i+1] == '+') {
            current *= (s[i]-'0') % 2;
            result += current;
            current = 1;
        }
        if (s[i+1] == '*') {
            current *= (s[i]-'0') % 2;
        }
    }
    cout << result % 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while (n--) solve();
}
