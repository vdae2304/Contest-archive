#include <bits/stdc++.h>
using namespace std;
main() {
    int N, M, K;
    cin >> N >> M >> K;
    cout << K + (M + 1) / 2 + (max(N - K - 2 * (M % 2), 0) + 3) / 4;
}
