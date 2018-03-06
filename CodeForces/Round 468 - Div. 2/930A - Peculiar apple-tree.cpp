#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'000

int N, P, ans, H[MAXN];
vector<int> tree[MAXN];

int DFS(int u, int h) {
    H[h]++;
    for (int v : tree[u])
        DFS(v, h + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> P;
        tree[P].push_back(i);
    }

    DFS(1, 0);
    for (int i = 0; i <= N; i++)
        ans += H[i] % 2;

    cout << ans;
    return 0;
}
