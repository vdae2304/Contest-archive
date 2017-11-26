#include <bits/stdc++.h>
using namespace std;

int N, L, x;
bool Kefa[100], Sasha[100];

bool Compara(int i) {
    for (int j = 0; j < L; j++)
        if (Kefa[j] != Sasha[(i + j) % L])
            return false;
    return true;
}

bool Checar() {
    for (int i = 0; i < L; i++)
        if (Compara(i))
            return true;
    return false;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> x;
        Kefa[x] = true;
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        Sasha[x] = true;
    }

    if (Checar())
        cout << "YES\n";
    else
        cout << "NO\n";
}
