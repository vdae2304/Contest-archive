#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int C, N;
    cin >> C >> N;

    bool v[2 * N];
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        v[N + i] = v[i];
    }

    int menor = INFINITY, cont = 0;
    for (int i = 0, j = 0; i < 2 * N; i++) {
        for (; cont < C && j < 2 * N; j++)
            if (!v[j])
                cont++;
        if (cont == C)
            menor = min(menor, j - i - C);
        if (!v[i])
            cont--;
    }

    cout << menor;
}
