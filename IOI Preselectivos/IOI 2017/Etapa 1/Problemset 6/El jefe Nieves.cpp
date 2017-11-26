#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000

int N, down[MAXN], up[MAXN];
vector<int> A[MAXN], B[MAXN];

//Construct tree with root in node 0 (return number of changes needed)
int tree(int node, int parent, int dirA, int dirB) {
    int S = 0;

    for (int i = 0; i < A[node].size(); i++)
        if (A[node][i] != parent)
            S += tree(A[node][i], node, dirA, dirB + 1);

    for (int i = 0; i < B[node].size(); i++)
        if (B[node][i] != parent)
            S += tree(B[node][i], node, dirA + 1, dirB) + 1;

    down[node] = dirA;
    up[node] = dirB;
    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        A[x - 1].push_back(y - 1);
        B[y - 1].push_back(x - 1);
    }

    int changes = tree(0, 0, 0, 0), min_changes = changes;
    for (int i = 1; i < N; i++)
        min_changes = min(min_changes, changes - down[i] + up[i]);

    cout << min_changes << "\n";
    for (int i = 0; i < N; i++)
        if (changes - down[i] + up[i] == min_changes)
            cout << i + 1 << " ";
}
