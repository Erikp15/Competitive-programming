#include <iostream>
#include <string>
#include <cmath>

#define HASH_T __uint128_t

HASH_T getHash(std::string s) {
    HASH_T power = 1;
    HASH_T ans = 0;
    for (auto &x: s) {
        ans += power * (x - 'a');
        power *= 26;
    }
    return ans;
}
int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    HASH_T h1 = getHash(s1.substr(0, s2.size()));
    HASH_T h2 = getHash(s2);
    int cnt = 0;
    for (int i = s2.size(); i < s1.size(); i++) {
        //std::cout << h1 << " " << h2 << std::endl;
        if (h1 == h2)
            cnt++;
        h1 -= pow(26, s2.size() - 1) * (s1[i - s2.size()] - 'a');
        h1 *= 26;
        h1 += s1[i] - 'a';
    }
    if (h1 == h2)
            cnt++;
    std::cout << cnt << std::endl;
    return 0;
}
