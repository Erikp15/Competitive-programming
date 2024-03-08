#include <iostream>
#include <string>

int cnt[(int)1e6 + 10];

int getHash(std::string s) {
    int power = 1;
    int ans = 0;
    for (auto &x: s) {
        ans += power * (x - 'a');
        power *= 26;
    }
    return ans;
}

void add(std::string s) {
    cnt[getHash(s)]++;
}

void remove(std::string s) {
    if (cnt[getHash(s)])
        cnt[getHash(s)]--;
}

int find(std::string s) {
    return cnt[getHash(s)];
}

int main() {
    int n;
    std::cin >> n;
    for (int q = 0; q < n; q++) {
        char t;
        std::string s;
        std::cin >> t >> s;
        switch(t) {
            case 'a':
                add(s);
                break;
            case 'r':
                remove(s);
                break;
            case 's':
                std::cout << find(s) << std::endl;
                break;
        }
    }
    return 0;
}
