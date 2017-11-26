#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000000

struct node {
    int s;
    char c;
    node *l, *r;
};

typedef node* pnode;

int N, idx, last;
node memo[MAXN];
pnode v[MAXN];

pnode newNode(char c = 0) {
    memo[last].s = 1;
    memo[last].c = c;
    memo[last].l = memo[last].r = nullptr;
    return &memo[last++];
}

int Count(pnode p) {
    return p ? p -> s : 0;
}

char Kth(pnode p, int k) {
    if (Count(p -> l) + 1 == k)
        return p -> c;
    else if (Count(p -> l) >= k)
        return Kth(p -> l, k);
    else
        return Kth(p -> r, k - Count(p -> l) - 1);
}

pnode Merge(pnode l, pnode r) {
    if (!l || !r)
        return l ? l : r;
    pnode x = newNode();
    if (abs(rand() % (l -> s + r -> s)) < l -> s) {
        x -> c = l -> c;
        x -> l = l -> l;
        x -> r = Merge(l -> r, r);
    }
    else {
        x -> c = r -> c;
        x -> r = r -> r;
        x -> l = Merge(l, r -> l);
    }
    x -> s = Count(x -> l) + Count(x -> r) + 1;
    return x;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a; int b;
        cin >> a;

        if (a == 'T') {
            cin >> a;
            v[++idx] = Merge(v[idx - 1], newNode(a));
        }
        else if (a == 'U') {
            cin >> b;
            v[++idx] = v[idx - 1 - b];
        }
        else {
            cin >> b;
            cout << Kth(v[idx], b + 1) << "\n";
        }
    }
}
