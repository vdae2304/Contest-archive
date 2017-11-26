#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXB 39

struct nodo {
    nodo *sig[2];
};

int N;
long long v[MAXN], pre, suf, ans;
nodo *trie = new nodo();

void Insertar(long long n) {
    nodo *pos = trie;
    for (int i = MAXB; i >= 0; i--) {
        bool bit = n & (1ll << i);
        if (pos -> sig[bit] == NULL)
            pos -> sig[bit] = new nodo();
        pos = pos -> sig[bit];
    }
}

long long Busqueda(long long n) {
    nodo *pos = trie;
    long long m = 0;
    for (int i = MAXB; i >= 0; i--) {
        bool bit = n & (1ll << i);
        if (pos -> sig[!bit] != NULL)
            bit = !bit;
        if (bit)
            m |= (1ll << i);
        pos = pos -> sig[bit];
    }
    return m;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        suf ^= v[i];
    }

    for (int i = 0; i <= N; i++) {
        Insertar(pre);
        ans = max(ans, suf ^ Busqueda(suf));
        pre ^= v[i];
        suf ^= v[i];
    }

    cout << ans;
}
