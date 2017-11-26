#include <iostream>
using namespace std;

int N, F, B, S;
int Pascal[14][14], Stirling[14][14];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> F >> B;

    for (int i = 0; i < N; i++) {
        Pascal[i][0] = Pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
            Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
    }

    Stirling[0][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            Stirling[i][j] = Stirling[i - 1][j - 1] + (i - 1) * Stirling[i - 1][j];

    for (int i = 0; i < N; i++)
        S += Pascal[N - 1][i] * Stirling[i][F - 1] * Stirling[N - i - 1][B - 1];
    
    cout << S;
}
