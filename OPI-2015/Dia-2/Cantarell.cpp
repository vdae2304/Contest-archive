#include <iostream>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, aux;
    cin >> N;

    int c[3][N + 1];
    c[1][0] = 0;
    c[2][0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> aux;
        c[1][i] = c[1][i - 1];
        c[2][i] = c[2][i - 1];
        c[aux][i]++;
    }

    int menor = c[1][N];
    for (int i = 1; i <= N; i++)
        menor = min(menor, c[2][i] + c[1][N] - c[1][i]);
    cout << menor;
}
