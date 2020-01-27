#include <iostream>
#include <utility>
using namespace std;
typedef pair<char, int> pii;
int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	int n;
	cin >> n;
 
	pii a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = n + i;
	}
 
	for (int i = 0; i < n / 2; i++) {
		if (a[i].first == b[i].first)
			continue;
		if ((a[i].first == a[n - 1 - i].first || b[i].first == b[n - 1 - i].first) && 
			(a[i].first != b[n - 1 - i].first && b[i].first != a[n - 1 - i].first))
			swap(a[i], b[i]);
		if (a[i].first == b[n - 1 - i].first)
			swap(b[i], b[n - 1 - i]);
		else if (b[i].first == a[n - 1 - i].first)
			swap(a[i], a[n - 1 - i]);
	}
 
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i].first != b[i].first) {
			if (a[i].second < n || b[i].second < n)
				ans++;
			else
				ans += 2;
		}
	cout << ans << "\n";
	
	return 0;
}