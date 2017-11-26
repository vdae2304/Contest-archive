#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef pair<int, int> pii;
typedef pair<int, pii> tup;

int N, M, Q;
tup edges[4 * MAXN];
vector<pii> tree[MAXN];
int P[MAXN], H[MAXN], Pa[MAXN], C[MAXN], L[MAXN];

int Find(int u) {
    if (P[u] != u)
        P[u] = Find(P[u]);
    return P[u];
}

void Union(int u, int v, int c) {
    int a = Find(u), b = Find(v);
    if (a != b) {
        if (H[a] > H[b])
            P[b] = a;
        else if (H[a] < H[b])
            P[a] = b;
        else {
            P[b] = a;
            H[a]++;
        }
        tree[u].push_back(pii(v, c));
        tree[v].push_back(pii(u, c));
    }
}

void DFS(int u, int p) {
    for (pii nxt : tree[u])
        if (nxt.first != p) {
            Pa[nxt.first] = u;
            C[nxt.first] = nxt.second;
            L[nxt.first] = L[u] + 1;
            DFS(nxt.first, u);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < M; i++)
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges, edges + M);

    for (int i = 1; i <= N; i++)
        P[i] = i;
    for (int i = M - 1; i >= 0; i--)
        Union(edges[i].second.first, edges[i].second.second, edges[i].first);
    DFS(1, 0);

    cin >> Q;
    while (Q--) {
        int s, t, ans = INT_MAX;
        cin >> s >> t;

        if (L[s] > L[t])
            swap(s, t);
        while (L[s] < L[t]) {
            ans = min(ans, C[t]);
            t = Pa[t];
        }
        while (s != t) {
            ans = min(ans, min(C[s], C[t]));
            s = Pa[s];
            t = Pa[t];
        }

        cout << ans - 1 << "\n";
    }
}
