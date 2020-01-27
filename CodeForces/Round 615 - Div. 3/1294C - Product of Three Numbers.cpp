#include <bits/stdc++.h>
using namespace std;
 
int get_factor(int n, int start) {
	for (int i = start; i * i < n; ++i)
		if (n % i == 0)
			return i;
	return 1;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int a = get_factor(n, 2);
		int b = get_factor(n / a, a + 1);
		int c = n / (a * b);
		if (a != 1 && b != 1 && c != 1 && a != b && a != c && b != c) 
			cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
		else
			cout << "NO\n";
	}
	return 0;
}