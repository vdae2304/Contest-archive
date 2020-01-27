#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	int T;
	long long a, b, c, n;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> n;
		long long cnt = 3*max(a, max(b, c)) - a - b - c;
		if (n - cnt < 0 || (n - cnt) % 3)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}