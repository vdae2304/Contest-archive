#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
#define MAXN 300'000
 
lld n, q, idx[MAXN], sz[MAXN];
vector<lld> tree[MAXN], preorder;
 
void DFS(lld u) {
    sz[u] = 1;
    idx[u] = preorder.size();
    preorder.push_back(u);
    for (lld v : tree[u]) {
        DFS(v);
        sz[u] += sz[v];
    }
}
 
lld Query(lld u, lld k) {
    if (sz[u] < k)
        return -1;
    return preorder[idx[u] + k - 1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    lld p, u, k;
    cin >> n >> q;
 
    for (lld i = 2; i <= n; i++) {
        cin >> p;
        tree[p].push_back(i);
    }
    DFS(1);
 
    while (q--) {
        cin >> u >> k;
        cout << Query(u, k) << "\n";
    }
    return 0;
}