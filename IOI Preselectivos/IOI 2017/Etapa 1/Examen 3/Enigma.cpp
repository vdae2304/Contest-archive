#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000000

int N;
long long DP[2010][8][8]; //Guardamos tambien las ultimas 2 columnas

void SumaModulo(long long &a, long long &b) {
    a = (a + b) % MOD;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    DP[0][0b111][0b111] = 1;
    for (int i = 0; i < N; i++) {
        SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b111]); //Pieza 1
        SumaModulo(DP[i + 2][0b111][0b010], DP[i][0b111][0b111]); //Pieza 2
        SumaModulo(DP[i + 2][0b111][0b101], DP[i][0b111][0b111]); //Pieza 6
        SumaModulo(DP[i + 2][0b111][0b110], DP[i][0b111][0b111]); //Pieza 12
        SumaModulo(DP[i + 2][0b111][0b100], DP[i][0b111][0b111]); //Pieza 14
        SumaModulo(DP[i + 2][0b111][0b001], DP[i][0b111][0b111]); //Pieza 18
        SumaModulo(DP[i + 2][0b111][0b011], DP[i][0b111][0b111]); //Pieza 22.
        if (i >= 2) {
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b010]); //Pieza 3
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b100]); //Pieza 4
            SumaModulo(DP[i + 2][0b111][0b010], DP[i][0b111][0b101]); //Pieza 5
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b101]); //Pieza 7
            SumaModulo(DP[i + 1][0b111][0b110], DP[i][0b111][0b100]); //Pieza 10
            SumaModulo(DP[i + 1][0b111][0b011], DP[i][0b111][0b001]); //Pieza 11
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b001]); //Pieza 13
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b011]); //Pieza 15
            SumaModulo(DP[i + 2][0b110][0b100], DP[i][0b111][0b100]); //Pieza 16
            SumaModulo(DP[i + 2][0b011][0b001], DP[i][0b111][0b001]); //Pieza 17
            SumaModulo(DP[i + 1][0b111][0b111], DP[i][0b111][0b110]); //Pieza 19
            SumaModulo(DP[i + 2][0b111][0b100], DP[i][0b111][0b011]); //Pieza 20
            SumaModulo(DP[i + 2][0b111][0b001], DP[i][0b111][0b110]); //Pieza 21
        }
        if (i >= 3) {
            SumaModulo(DP[i + 1][0b111][0b110], DP[i][0b110][0b100]); //Pieza 8
            SumaModulo(DP[i + 1][0b111][0b011], DP[i][0b011][0b001]); //Pieza 9
        }
    }
    cout << DP[N][0b111][0b111];
}
