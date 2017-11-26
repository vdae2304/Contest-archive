#include <bits/stdc++.h>
using namespace std;

//Current position (i), Ink left (d), Seconds (t)
struct pos {
    int i, d, t;
};

bool operator < (pos a, pos b) {
    return a.t > b.t;
}

int N, D;
char C[1010];
bool visitado[1010][1010];
priority_queue<pos> cola;

void Busqueda(pos q) {
    cola.pop();

    if (q.i >= N - 1) {
        cout << q.t;
        exit(0);
    }

    //Already visited
    if (visitado[q.i][q.d])
        return;
    visitado[q.i][q.d] = true; //We mark it

    int max_d, max_j;

    //Distance jumping
    switch (C[q.i]) {
        case 'N': max_j = 3; break;
        case '-': max_j = 2; break;
        case 'A': max_j = 1;
    }
    cola.push(pos {q.i + max_j, q.d, q.t + 1});

    //Distance walking
    for (max_d = 1; max_d <= max_j && C[q.i + max_d] == C[q.i]; max_d++);
    cola.push(pos {q.i + max_d, q.d, q.t + 1});

    //If we have ink left we use it
    if (q.d > 0) {
        cola.push(pos {q.i + 6, q.d - 1, q.t + 2});
        cola.push(pos {q.i + 4, q.d - 1, q.t + 1});
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> D;

    for (int i = 0; i < N; i++)
        cin >> C[i];

    cola.push(pos {0, D, 0});
    while (!cola.empty()) 
        Busqueda(cola.top());
}
