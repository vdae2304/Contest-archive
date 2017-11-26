#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001

int N, T[MAXN], S[MAXN];
vector<int> tree[MAXN];

void getSum(int node, int parent) {
    S[node] = T[node];
    for (int nxt : tree[node])
        if (nxt != parent) {
            getSum(nxt, node);
            S[node] += S[nxt];
        }
}

int DFS1(int node, int parent, int A) {
    int B = 0;
    if (3 * S[node] == S[tree[0][0]]) {
        if (A) {
            cout << A << " " << node << "\n";
            exit(0);
        }
        else
            B = node;
    }
    for (int nxt : tree[node])
        if (nxt != parent)
            A = max(A, DFS1(nxt, node, A));
    return max(A, B);
}

void DFS2(int node, int parent, int A) {
    if (node != tree[0][0]) {
        if (A && 3 * S[node] == S[tree[0][0]]) {
            cout << A << " " << node << "\n";
            exit(0);
        }
        if (!A && 3 * S[node] == 2 * S[tree[0][0]])
            A = node;
    }
    for (int nxt : tree[node])
        if (nxt != parent)
            DFS2(nxt, node, A);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1, parent; i <= N; i++) {
        cin >> parent >> T[i];
        tree[parent].push_back(i);
    }

    getSum(tree[0][0], 0);
    DFS1(tree[0][0], 0, 0);
    DFS2(tree[0][0], 0, 0);

    cout << "-1\n";
}
