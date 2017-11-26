#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

int N, ans;
bool ciclo[MAXN], visitado[MAXN];
int Posee[MAXN], Deuda[MAXN], DebeA[MAXN];
vector<int> RecibeDe[MAXN];

void ResuelveCiclo(int i) {
    int j = i;
    for (int r = DebeA[i]; r != i; r = DebeA[r])
        if (Deuda[r] - Posee[r] < Deuda[j] - Posee[j])
            j = r;
    ans += max(Deuda[j] - Posee[j], 0);
    Posee[j] = Deuda[j];

    i = j;
    do {
        ans += max(Deuda[DebeA[j]] - Posee[DebeA[j]] - Deuda[j], 0);
        Posee[DebeA[j]] += Deuda[j];
        j = DebeA[j];
    }
    while (j != i);
}

int Busqueda(int i, int prev) {
    if (visitado[i]) {
        ciclo[i] = true;
        for (int j = DebeA[i]; j != i; j = DebeA[j])
            ciclo[j] = true;
        return i;
    }
    else {
        int aux = 0;
        visitado[i] = true;

        for (int j = 0; j < RecibeDe[i].size(); j++)
            if (RecibeDe[i][j] != prev) {
                int ret = Busqueda(RecibeDe[i][j], 0);
                aux = ret ? ret : aux;
            }

        if (!ciclo[i] && Posee[i] < Deuda[i]) {
            ans += Deuda[i] - Posee[i];
            Posee[i] = Deuda[i];
        }
        if (!ciclo[i] && Posee[i] >= Deuda[i])
            Posee[DebeA[i]] += Deuda[i];

        if (!visitado[DebeA[i]]) {
            int ret = Busqueda(DebeA[i], i);
            aux = ret ? ret : aux;
        }
        return aux;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> DebeA[i] >> Deuda[i];
        RecibeDe[DebeA[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++)
        if (!visitado[i])
            ResuelveCiclo(Busqueda(i, 0));

    cout << ans;
}
