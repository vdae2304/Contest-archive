#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    map<int, int> stars;
    cin >> N;

    while (N--) {
        int x, y;
        cin >> x >> y;
        if (stars.find(x) == stars.end() || y < stars[x])
            stars[x] = y;
    }

    cout << stars.size();
    for (auto i = stars.begin(); i != stars.end(); i++)
        cout << "\n" << i -> first << " " << i -> second;
}
