#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int sig[26];
    bool fin;
} trie[2000000];

int N, ans, ultimo = 1;
string P, Q;
bool esParte[500000];

void Insertar() {
    int pos = 1;
    for (int i = 0; i < P.size(); i++) {
        if (!trie[pos].sig[P[i] - 'A'])
            trie[pos].sig[P[i] - 'A'] = ++ultimo;
        pos = trie[pos].sig[P[i] - 'A'];
    }
    trie[pos].fin = true;
}

void Busqueda(int i) {
    int pos = 1;
    for (int j = 0; pos; j++) {
        if (trie[pos].fin) {
            esParte[i + j] = true;
            ans = max(ans, i + j);
        }
        pos = trie[pos].sig[Q[i + j] - 'A'];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    while (N--) {
        cin >> P;
        Insertar();
    }

    cin >> Q;
    esParte[0] = true;
    for (int i = 0; i < Q.size(); i++)
        if (esParte[i])
            Busqueda(i);

    cout << ans;
}
