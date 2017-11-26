#include <bits/stdc++.h>
using namespace std;

struct node {
    int s;
    char c;
    node *l, *r;
    node(int x = 0, char y = 0) : s(x), c(y), l(nullptr), r(nullptr) {};
};

typedef node* pnode;

int Count(pnode p) {
    return p ? p -> s : 0;
}

char Kth(pnode p, int k) {
    if (Count(p -> l) + 1 == k) return p -> c;
    if (Count(p -> l) >= k) return Kth(p -> l, k);
    return Kth(p -> r, k - Count(p -> l) - 1);
}

pnode Merge(pnode l, pnode r) {
    if (!l || !r)
        return l ? l : r;
    pnode x = new node();
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
    int N;
    cin >> N;

    vector<pnode> v (1, nullptr);
    for (int i = 0; i < N; i++) {
        char a; int b;
        cin >> a;

        if (a == 'T') {
            cin >> a;
            v.push_back(Merge(v.back(), new node(1, a)));
        }
        else if (a == 'U') {
            cin >> b;
            v.push_back(v[v.size() - 1 - b]);
        }
        else {
            cin >> b;
            cout << Kth(v.back(), b + 1) << "\n";
        }
    }
}
