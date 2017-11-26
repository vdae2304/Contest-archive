#include <bits/stdc++.h>
using namespace std;

int N, P;
string nombre[1000];
bool amistad[1000][1000];

int indice(int a, int b, string x) {
    int m = (a + b) / 2;
    if (nombre[m] == x)
        return m;
    else if (nombre[m] > x)
        return indice(a, m - 1, x);
    else
        return indice(m + 1, b, x);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nombre[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> amistad[i][j];

    cin >> P;
    for (int i = 0; i < P; i++) {
        string a, b;
        cin >> a >> b;
        cout << amistad[indice(0, N, a)][indice(0, N, b)] << endl;
    }
}
