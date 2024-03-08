#include<iostream>

int cnt(int n, int k) {
	if (n == 0 || k == 0 || k > n)
		return 0;
	if (k == 1 || k == n)
		return 1;

	return  k * cnt(n - 1, k) + cnt(n - 1, k - 1);
}

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << cnt(n, k);
	return 0;
}
