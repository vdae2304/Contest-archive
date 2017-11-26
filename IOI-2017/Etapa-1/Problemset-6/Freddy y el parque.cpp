#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, M;
vector<int> child[MAXN];
bool cat[MAXN];

int solve(int node, int parent, int cont) {
    cont = cat[node] ? cont + 1 : 0;

    if (cont > M)
        return 0;

    if (child[node].size() == 1)
        return 1;
    else {
        int S = 0;
        for (int i = 0; i < child[node].size(); i++)
            if (child[node][i] != parent)
                S += solve(child[node][i], node, cont);
        return S;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> cat[i];

    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        child[x - 1].push_back(y - 1);
        child[y - 1].push_back(x - 1);
    }

    cout << solve(0, 0, 0);
}
