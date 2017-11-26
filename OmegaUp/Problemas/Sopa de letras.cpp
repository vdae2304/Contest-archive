#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int mov[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
char Sopa[100][100];

string aparece(string s) {
    for (int k = 0; k < 4; k++) {
        int a = mov[0][k] < 0 ? s.size() - 1 : 0;
        int b = mov[1][k] < 0 ? s.size() - 1 : 0;
        int x = mov[0][k] > 0 ? N - s.size() : N - 1;
        int y = mov[1][k] > 0 ? M - s.size() : M - 1;

        for (int i = a; i <= x; i++)
            for (int j = b; j <= y; j++) {
                bool coincide = true;

                for (int l = 0; coincide && l < s.size(); l++)
                    if (s[l] != Sopa[i + l * mov[0][k]][j + l * mov[1][k]])
                        coincide = false;

                if (coincide)
                    return "si\n";
            }
    }
    return "no\n";
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Sopa[i][j];

    cin >> K;
    while (K--) {
        string s;
        cin >> s;
        cout << aparece(s);
    }
}
