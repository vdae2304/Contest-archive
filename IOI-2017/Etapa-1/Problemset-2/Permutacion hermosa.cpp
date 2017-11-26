#include <bits/stdc++.h>
using namespace std;
main() {
    int N, K;
    cin >> N >> K;
    if (N == K)
        cout << "-1";
    else if (K == N - 1) {
        for (int i = 1; i <= N; i++)
            cout << i << " ";
    }
    else {
        cout << K + 2 << " ";
        for (int i = 2; i < K + 2; i++)
            cout << i << " "; //P[i] = i
        for (int i = K + 2; i < N; i++)
            cout << i + 1 << " "; //P[i] = i + 1
        cout << "1";
    }
}
