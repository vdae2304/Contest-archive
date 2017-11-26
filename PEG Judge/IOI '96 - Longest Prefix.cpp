#include <bits/stdc++.h>
using namespace std;

struct nodo {
    bool fin;
    nodo *sig[26];
    nodo() : fin(false) {memset(sig, 0, sizeof sig);}
} *trie = new nodo();

string P, Q;
int ans;
bitset<1000000> esParte;

void Insertar() {
    nodo *p = trie;
    for (int i = 0; i < P.size(); i++) {
        if (!p -> sig[P[i] - 'A'])
            p -> sig[P[i] - 'A'] = new nodo();
        p = p -> sig[P[i] - 'A'];
    }
    p -> fin = true;
}

void Busqueda(int i) {
    nodo *p = trie;
    for (int j = 0; p; j++) {
        if (p -> fin) {
            esParte[i + j] = true;
            ans = max(ans, i + j);
        }
        p = p -> sig[Q[i + j] - 'A'];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> P;
    while (P != ".") {
        Insertar();
        cin >> P;
    }

    while (cin >> P)
        Q.append(P);

    esParte[0] = true;
    for (int i = 0; i < Q.size(); i++)
        if (esParte[i])
            Busqueda(i);

    cout << ans;
}
