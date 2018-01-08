#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

int N, P;
vector<int> tree[MAXN];

bool isLeaf(int u, int p) {
    int leaf = 0, child = 0;
    for (int v : tree[u])
        if (v != p) {
            leaf += isLeaf(v, u);
            child++;
        }
    if (child && leaf < 3) {
        cout << "No\n";
        exit(0);
    }
    return !child;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> P;
        tree[P].push_back(i);
    }

    isLeaf(1, 1);
    cout << "Yes\n";
    return 0;
}
