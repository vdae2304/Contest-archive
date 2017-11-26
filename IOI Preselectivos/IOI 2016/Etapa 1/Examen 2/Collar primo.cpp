#include <bits/stdc++.h>
using namespace std;

int N, v[19];
bitset<38> primo (0b10000010100000100010100010100010101100);

int Busqueda(int i) {
    if (i >= N - 1)
        return primo[v[N - 1] + v[0]];
    else {
        int S = 0;
        for (int j = i + 1; j < N; j++)
            if (primo[v[i] + v[j]]) {
                swap(v[i + 1], v[j]);
                S += Busqueda(i + 1);
                swap(v[i + 1], v[j]);
            }
        return S;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        v[i] = i + 1;

    if (N % 2)
        cout << "0";
    else
        cout << Busqueda(0);
}
