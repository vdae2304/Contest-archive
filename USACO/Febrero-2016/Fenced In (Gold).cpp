#include <bits/stdc++.h>
using namespace std;
#define MAXN 2001

int A, B, N, M;
int V[MAXN], H[MAXN];

long long cost;
int parent[MAXN * MAXN], height[MAXN * MAXN];

int getNode(int i, int j) {
    return M * i + j;
}

int Find(int node) {
    if (parent[node] == node)
        return node;
    parent[node] = Find(parent[node]);
    return parent[node];
}

void Union(int u, int v, int d) {
    int a = Find(u), b = Find(v);
    if (a != b) {
        if (height[a] < height[b])
            parent[a] = b;
        else if (height[b] < height[a])
            parent[b] = a;
        else {
            parent[a] = b;
            height[b]++;
        }
        cost += d;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fencedin.in");
    ofstream cout("fencedin.out");
    cin >> A >> B >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> V[i];
    for (int i = 0; i < M; i++)
        cin >> H[i];

    sort(V, V + N + 1);
    for (int i = 0; i < N; i++)
        V[i] = V[i + 1] - V[i];
    V[N] = A - V[N];
    sort(V, V + ++N);

    sort(H, H + M + 1);
    for (int i = 0; i < M; i++)
        H[i] = H[i + 1] - H[i];
    H[M] = B - H[M];
    sort(H, H + ++M);

    for (int i = 0; i < N * M; i++)
        parent[i] = i;

    for (int i = 0, j = 0; i < N || j < M; ) {
        if (j == M || (i < N && V[i] < H[j])) {
            for (int k = 0; k < M - 1; k++)
                Union(getNode(i, k), getNode(i, k + 1), V[i]);
            i++;
        }
        else {
            for (int k = 0; k < N - 1; k++)
                Union(getNode(k, j), getNode(k + 1, j), H[j]);
            j++;
        }
    }

    cout << cost << "\n";
}
