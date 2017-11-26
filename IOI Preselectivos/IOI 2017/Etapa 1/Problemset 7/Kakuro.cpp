#include <bits/stdc++.h>
using namespace std;

int N, val[10];
bool usado[10];

int maxNum[7][7];
bool imposible[10][10];

int Kakuro[7][7];
char Mapa[7][7];
pair<string, string> pista[7][7];

bool celda_blanca(int i, int j) {
    return i < N && j < N && Mapa[i][j] != '#' && Mapa[i][j] != '(';
}

void cancelar(string &s, int l) {
    int a = l * (l + 1) / 2, b = 45 - (9 - l) * (10 - l) / 2;
    if (s.size() > 1) {
        if (l == 2)
            imposible[s[1] - 'A'][9] = imposible[s[1] - 'A'][8] = true;
        a /= 10, b /= 10;
    }
    for (int i = 0; i < a; i++)
        imposible[s[0] - 'A'][i] = true;
    for (int i = b + 1; i < 10; i++)
        imposible[s[0] - 'A'][i] = true;
}

void restringe(int i, int j, int l) {
    int a = 9 - l * (l - 1) / 2;
    maxNum[i][j] = min(maxNum[i][j], a);
    if (Mapa[i][j] != 'O')
        for (int k = a + 1; k < 10; k++)
            imposible[Mapa[i][j] - 'A'][k] = true;
}

void precalcular() {
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--) {
            maxNum[i][j] = 9;

            if ('A' <= Mapa[i][j] && Mapa[i][j] <= 'J')
                imposible[Mapa[i][j] - 'A'][0] = true;
            else if (Mapa[i][j] == '(') {
                if (pista[i][j].first != ".") {
                    int l = 0;

                    imposible[pista[i][j].first[0] - 'A'][0] = true;
                    for (int k = j + 1; celda_blanca(i, k); k++, l++);
                    cancelar(pista[i][j].first, l);

                    if (pista[i][j].first.size() == 1)
                        for (int k = j + 1; celda_blanca(i, k); k++)
                            restringe(i, k, l);
                 }
                 if (pista[i][j].second != ".") {
                    int l = 0;

                    imposible[pista[i][j].second[0] - 'A'][0] = true;
                    for (int k = i + 1; celda_blanca(k, j); k++, l++);
                    cancelar(pista[i][j].second, l);

                    if (pista[i][j].second.size() == 1)
                        for (int k = i + 1; celda_blanca(k, j); k++)
                            restringe(k, j, l);
                 }
             }
        }
}

int convierte(string &s) {
    int m = 0;
    for (int i = 0; i < s.size(); i++)
        m = 10 * m + val[s[i] - 'A'];
    return m;
}

void elimina(bool aux[10], int m) {
    for (int i = 0; i < 10; i++)
        if (i != m)
            aux[i] = true;
}

void resolver(int i, int j) {
    while (i < N && !celda_blanca(i, j)) {
        i += ++j / N;
        j %= N;
    }

    int Si = i, Sj = j + 1;
    if (Sj == N)
        Si++, Sj = 0;

    if (i >= N) {
        if (val[0])
            cout << val[0];
        for (int k = 1; k < 10; k++)
            cout << val[k];
        exit(0);
    }

    bool aux[10] = {};

    if (Mapa[i][j] != 'O')
        elimina(aux, val[Mapa[i][j] - 'A']);

    for (int k = j - 1; celda_blanca(i, k); k--)
        aux[Kakuro[i][k]] = true;
    for (int k = i - 1; celda_blanca(k, j); k--)
        aux[Kakuro[k][j]] = true;

    if (!celda_blanca(i, j + 1)) {
        int A = 0;
        for (int k = j - 1; ; k--) {
            if (Mapa[i][k] == '(') {
                A = convierte(pista[i][k].first) - A;
                if (A < 1 || A > 9 || aux[A])
                    return;
                elimina(aux, A);
                break;
            }
            else
                A += Kakuro[i][k];
        }
    }
    if (!celda_blanca(i + 1, j)) {
        int A = 0;
        for (int k = i - 1; ; k--) {
            if (Mapa[k][j] == '(') {
                A = convierte(pista[k][j].second) - A;
                if (A < 1 || A > 9 || aux[A])
                    return;
                elimina(aux, A);
                break;
            }
            else
                A += Kakuro[k][j];
        }
    }

    for (int k = 1; k <= maxNum[i][j]; k++)
        if (!aux[k]) {
            Kakuro[i][j] = k;
            resolver(Si, Sj);
            Kakuro[i][j] = 0;
        }
}

void enumera(int i) {
    if (i == 10)
        resolver(1, 1);
    else {
        for (int j = 0; j < 10; j++)
            if (!usado[j] && !imposible[i][j]) {
                val[i] = j;
                usado[j] = true;
                enumera(i + 1);
                val[i] = 0;
                usado[j] = false;
            }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    char c;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> Mapa[i][j];
            if (Mapa[i][j] == '(') {
                cin >> c;
                while (c != ',') {
                    pista[i][j].first.push_back(c);
                    cin >> c;
                }
                cin >> c;
                while (c != ')') {
                    pista[i][j].second.push_back(c);
                    cin >> c;
                }
            }
        }

    precalcular();
    enumera(0);
}
