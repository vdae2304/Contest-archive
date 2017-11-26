#include <bits/stdc++.h>
using namespace std;

int N;
int izq[1001], der[1001];
int min_col[1001], max_col[1001], last_col;

void inorder(int node, int level) {
    if (node == -1)
        return;
    inorder(izq[node], level + 1);

    last_col++;
    if (!min_col[level])
        min_col[level] = last_col;
    max_col[level] = last_col;

    inorder(der[node], level + 1);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int level = 1, len = 1, x;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        cin >> izq[x] >> der[x];
    }
    inorder(1, 1);

    for (int i = 1; i <= N; i++) {
        int j = max_col[i] - min_col[i] + 1;
        if (j > len)
            level = i, len = j;
    }

    cout << level << " " << len;
}
