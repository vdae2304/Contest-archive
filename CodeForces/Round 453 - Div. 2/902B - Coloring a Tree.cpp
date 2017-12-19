#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, C[MAXN];
vector<int> tree[MAXN];

int DFS(int u, int c, int p) {
    int ans = (c != C[u]);

    for (int v : tree[u])
        if (v != p)
            ans += DFS(v, C[u], u);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 1, p; i < N; i++) {
        cin >> p;
        tree[i].push_back(p - 1);
        tree[p - 1].push_back(i);
    }

    for (int i = 0; i < N; i++)
        cin >> C[i];

    cout << DFS(1, 0, 1) << "\n";
    return 0;
}
