#include <bits/stdc++.h>
using namespace std;

struct punto {
    int x, y, i, c;
};

bool compara(punto a, punto b) {
    return a.x < b.x;
}

struct pareja {
    int i, j, d;
};

pareja menor(pareja a, pareja b) {
    return a.d < b.d ? a : b;
}

int N;
punto v[200000];

int calcula(int i, int j) {
    return (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
}

pareja Busqueda(int a, int b) {
    if (b - a <= 1)
        return pareja {0, 0, INFINITY};
    else if (b - a == 2)
        return pareja{a, a + 1, calcula(a, a + 1)};
    else {
        int m = (a + b) / 2;
        pareja r = menor(Busqueda(a, m), Busqueda(m, b));

        for (int i = m - 1; i >= a && v[m].x - v[i].x <= r.d; i--)
            for (int j = m; j < b && v[j].x - v[i].x <= r.d; j++)
                r = menor(r, pareja {i, j, calcula(i, j)});

        return r;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (x >= 0 && y >= 0)
            v[i] = punto {x, y, i + 1, 1};
        else if (x < 0 && y >= 0)
            v[i] = punto {-x, y, i + 1, 2};
        else if (x >= 0 && y < 0)
            v[i] = punto {x, -y, i + 1, 3};
        else
            v[i] = punto {-x, -y, i + 1, 4};
    }
    sort(v, v + N, compara);

    pareja r = Busqueda(0, N);
    cout << v[r.i].i << " " << v[r.i].c << " " << v[r.j].i << " " << 5 - v[r.j].c;
}
