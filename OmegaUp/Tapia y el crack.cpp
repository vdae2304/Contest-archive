#include <bits/stdc++.h>
using namespace std;
#define MAXN 300001

struct nodo {
    int hijo[26];
    bool ok;
};

int N, M, total = 1;
string s;
nodo Dicc[MAXN];

void Agregar() {
    int pos = 1;
    for (int i = 0; i < s.size(); i++) {
        int l = (s[i] - 'a');
        if (!Dicc[pos].hijo[l])
            Dicc[pos].hijo[l] = ++total;
        pos = Dicc[pos].hijo[l];
    }
    Dicc[pos].ok = true;
}

bool Pregunta(int i, int pos, int dist) {
    if (i >= s.size())
        return (dist == 1 && Dicc[pos].ok);
    if (dist > 1)
        return false;
    for (int j = 0; j < 26; j++)
        if (Dicc[pos].hijo[j] && Pregunta(i + 1, Dicc[pos].hijo[j], dist + (s[i] - 'a' != j)))
            return true;
    return false;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    while (N--) {
        cin >> s;
        Agregar();
    }

    while (M--) {
        cin >> s;
        if (Pregunta(0, 1, 0))
            cout << "SI\n";
        else
            cout << "NO\n";
    }
}
