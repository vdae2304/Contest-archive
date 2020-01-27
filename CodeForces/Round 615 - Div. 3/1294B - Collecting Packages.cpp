#include <bits/stdc++.h>
using namespace std;
 
int T, n;
pair<int, int> v[2000];
 
string check() {
	pair<int, int> curr(0, 0);
	string ans = "YES\n";
	for (int i = 0; i < n; ++i) {
		if (v[i].second < curr.second)
			return "NO";
		ans.append(v[i].second - curr.second, 'R');
		ans.append(v[i].first - curr.first, 'U');
		curr = v[i];
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> v[i].second >> v[i].first;
		sort(v, v + n);
		cout << check() << '\n';
	}
	return 0;
}