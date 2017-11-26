#include <bits/stdc++.h>
using namespace std;

int N, Q, v[50000];
vector<int> STree[1000000];

void BuildTree(int node, int a, int b) {
    if (a == b)
        STree[node].push_back(v[a]);
    else {
        int m = (a + b) / 2, ChL = 2 * node + 1, ChR = 2 * node + 2;
        BuildTree(ChL, a, m); BuildTree(ChR, m + 1, b);
        STree[node].resize(STree[ChL].size() + STree[ChR].size());
        merge(STree[ChL].begin(), STree[ChL].end(), STree[ChR].begin(), STree[ChR].end(), STree[node].begin());
    }
}

int answer(int node, int a, int b, int i, int j, int x) {
    if (i > b || j < a)
        return 0;
    else if (i <= a && b <= j)
        return distance(upper_bound(STree[node].begin(), STree[node].end(), x), STree[node].end());
    else {
        int m = (a + b) / 2;
        return answer(2 * node + 1, a, m, i, j, x) + answer(2 * node + 2, m + 1, b, i, j, x);
    }
}

main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    BuildTree(0, 0, N - 1);

    scanf("%d", &Q);
    for (int i = 0, a, b, x; i < Q; i++) {
        scanf("%d %d %d", &a, &b, &x);
        printf("%d\n", answer(0, 0, N - 1, a - 1, b - 1, x));
    }
}
