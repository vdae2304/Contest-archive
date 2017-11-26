#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N, Q, v[MAXN];
vector<int> tree[MAXN];

long long sum[MAXN];
int pre[MAXN], post[MAXN], father[MAXN], A, B;

long long BuildTree(int node, int parent) {
    pre[node] = A++;
    father[node] = parent;
    for (int i = 0; i < tree[node].size(); i++)
        if (tree[node][i] != parent)
            sum[node] += BuildTree(tree[node][i], node);
    post[node] = B++;
    return sum[node] += v[node];
}

main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &v[i]);

    for (int i = 0, u, v; i < N - 1; i++) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    BuildTree(1, 1);

    scanf("%d", &Q);
    for (int i = 0, X, Y; i < Q; i++) {
        scanf("%d %d", &X, &Y);
        if (X == Y)
            printf("%lld\n", sum[1]);
        else if (pre[X] < pre[Y] || post[X] > post[Y])
            printf("%lld\n", sum[Y]);
        else {
            for (int j = 0; j < tree[Y].size(); j++)
                if (tree[Y][j] != father[Y] && pre[X] >= pre[tree[Y][j]] && post[X] <= post[tree[Y][j]])
                    printf("%lld\n", sum[1] - sum[tree[Y][j]]);
        }
    }
}
