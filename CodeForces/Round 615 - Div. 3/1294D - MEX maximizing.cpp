#include <bits/stdc++.h>
using namespace std;
#define maxn 8'000'000
typedef pair<int, int> ii;
 
int Q, x, y;
ii ST[maxn]; //Minimum, first ocurrence of minimum.
 
void build(int l, int r, int node) {
	ST[node] = ii(0, l);
	if (l < r) {
		int m = (l + r) / 2;
		build(l, m, 2*node + 1);
		build(m + 1, r, 2*node + 2);
	}
}
 
ii update(int i, int l, int r, int node) {
	if (l <= i && i <= r) {
		if (l == r) 
			ST[node].first++;
		else {
			int m = (l + r) / 2;
			ii ul = update(i, l, m, 2*node + 1);
			ii ur = update(i, m + 1, r, 2*node + 2);
			ST[node] = (ul.first <= ur.first) ? ul : ur;
		}
	}
	return ST[node];
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	cin >> Q >> x;
	build(0, x - 1, 0);
	while (Q--) {
		cin >> y;
		update(y % x, 0, x - 1, 0);
		cout << x * ST[0].first + ST[0].second << '\n';
	}
	return 0;
}