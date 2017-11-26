#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, C, cont = 0;
    cin >> N >> C;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N && v[i] + v[j] <= C; j++)
            cont++;

    cout << cont;
}
