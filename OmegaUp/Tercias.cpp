#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, S = 0;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1, k = i + 2; j < N; j++) {
            for (; k < N && v[k] - v[j] < v[j] - v[i]; k++);
            if (k < N && v[k] - v[j] == v[j] - v[i])
                S++;
        }

    cout << S;
}
