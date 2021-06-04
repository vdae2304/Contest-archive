#include <iostream>
using namespace std;

//Regresa el signo del numero dado.
int sign(int num) {
    if (num > 0)
        return 1;
    else if (num < 0)
        return -1;
    return 0;
}

int N, Q;       //Numero de elementos y numero de queries.
int v[200000];  //Arreglo.
int ST[400000]; //Segment Tree de signos de productos.

//Construye el Segment Tree.
int build(int i, int j, int n) {
    if (i == j)
        ST[n] = sign(v[i]);
    else
        ST[n] = build(i, (i + j)/2, 2*n + 1) * build((i + j)/2 + 1, j, 2*n + 2);
    return ST[n];
}

//Regresa el signo del producto de los elementos en el intervalo [l, r].
int query(int l, int r, int i, int j, int n) {
    if (j < l || r < i)
        return 1;
    if (l <= i && j <= r)
        return ST[n];
    return query(l, r, i, (i + j)/2, 2*n + 1) * query(l, r, (i + j)/2 + 1, j, 2*n + 2);
}

//Actualiza el elemento en la posicion k.
int update(int k, int val, int i, int j, int n) {
    if (i <= k && k <= j) {
        if (i == j)
            ST[n] = sign(val);
        else
            ST[n] = update(k, val, i, (i + j)/2, 2*n + 1) * update(k, val, (i + j)/2 + 1, j, 2*n + 2);
    }
    return ST[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    while (cin >> N >> Q) {
        //Lee el arreglo y construye el Segment Tree.
        for (int i = 1; i <= N; ++i)
            cin >> v[i];
        build(1, N, 0);
        
        //Lee las queries.
        while (Q--) {
            char op;
            int l, r;
            cin >> op >> l >> r;
            if (op == 'C')
                update(l, r, 1, N, 0);
            else switch (query(l, r, 1, N, 0)) {
                case -1: cout << "-"; break;
                case 0: cout << "0"; break;
                case 1: cout << "+";
            }
        }
        cout << '\n';
    }
}
