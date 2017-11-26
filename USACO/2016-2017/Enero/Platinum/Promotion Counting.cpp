#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N;
pair<int, int> v[MAXN];
vector<int> tree[MAXN];

int first[MAXN], last[MAXN], ind;
int BIT[MAXN], ans[MAXN];

void DFS(int node) {
    first[node] = ++ind;
    for (int i = 0; i < tree[node].size(); i++)
        DFS(tree[node][i]);
    last[node] = ind;
}

int Query(int i) {
    int S = 0;
    for (; i; i -= (i & -i))
        S += BIT[i];
    return S;
}

void Update(int i) {
    for (; i <= N; i += (i & -i))
        BIT[i]++;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("promote.in");
    ofstream cout("promote.out");
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v, v + N);

    for (int i = 2; i <= N; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    DFS(1);
    for (int i = N - 1; i >= 0; i--) {
        ans[v[i].second] = Query(last[v[i].second]) - Query(first[v[i].second]);
        Update(first[v[i].second]);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}
