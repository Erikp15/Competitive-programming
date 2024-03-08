#include <iostream>
#include <cassert>
int main() {
	int a, b;
	std::cin >> a >> b;
	assert(a >= 0 && a <= 2000000000);
	assert(b >= 0 && b <= 2000000000);
	int c = (a + b) / 2;
	assert(c >= 0 && c <= 2000000000);
	assert(c >= std::min(a, b));
	assert(c <= std::max(a, b));
	std::cout << c << '\n';
	return 0;
}
