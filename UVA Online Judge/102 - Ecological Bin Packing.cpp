#include <bits/stdc++.h>
using namespace std;

struct aux {
    char c;
    int w[3];
};

bool comp(aux a, aux b) {
    return a.c < b.c;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int v[9];

    while (cin >> v[0]) {
        int total = v[0], ans = INFINITY;
        string perm;
        aux orden[3] = {{'B', {0, 3, 6}}, {'C', {2, 5, 8}}, {'G', {1, 4, 7}}};

        for (int i = 1; i < 9; i++) {
            cin >> v[i];
            total += v[i];
        }

        do {
            int cambios = total;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (3 * i <= orden[i].w[j] && orden[i].w[j] < 3 * (i + 1))
                        cambios -= v[orden[i].w[j]];

            if (cambios < ans)
                ans = cambios, perm = {orden[0].c, orden[1].c, orden[2].c};
        }
        while (next_permutation(orden, orden + 3, comp));

        cout << perm << " " << ans << "\n";
    }
}
