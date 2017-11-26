#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

struct estado {
    int i, j;
};

int N, Q;
vector<int> tree[MAXN];

int ID[2][MAXN], indice;
stack<estado> pila;

void post_orden() {
    pila.push(estado {1, 0});
    while (!pila.empty()) {
        estado node = pila.top();
        pila.pop();

        if (node.j < tree[node.i].size()) {
            pila.push(estado {node.i, node.j + 1});
            pila.push(estado {tree[node.i][node.j], 0});
        }
        else {
            ID[1][node.i] = ++indice;
            if (tree[node.i].empty())
                ID[0][node.i] = indice;
            else
                ID[0][node.i] = ID[0][tree[node.i][0]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int A, B;
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        cin >> A >> B;
        tree[A].push_back(B);
    }

    post_orden();
    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        cout << !(ID[0][A] <= ID[1][B] && ID[1][B] <= ID[1][A]) << "\n";
    }
}
