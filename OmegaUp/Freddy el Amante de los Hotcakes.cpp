#include <bits/stdc++.h>
using namespace std;

struct node {
    int k, s;
    bool swp;
    node *l, *r;
    node(int x = 0) : k(x), s(1), swp(false), l(nullptr), r(nullptr) {};
};

typedef node* pnode;

int Count(pnode p) {
    return p ? p -> s : 0;
}

void Turn(pnode &p) {
    swap(p -> l, p -> r);
    if (p -> l)
        p -> l -> swp ^= 1;
    if (p -> r)
        p -> r -> swp ^= 1;
    p -> swp = false;
}

void Split(pnode p, int k, pnode &l, pnode &r) {
    if (p && p -> swp)
        Turn(p);
    if (!p)
        l = r = nullptr;
    else if (Count(p -> l) + 1 <= k) {
        Split(p -> r, k - Count(p -> l) - 1, p -> r, r);
        l = p;
        l -> s = Count(l -> l) + Count(l -> r) + 1;
    }
    else {
        Split(p -> l, k, l, p -> l);
        r = p;
        r -> s = Count(r -> l) + Count(r -> r) + 1;
    }
}

void Merge(pnode &p, pnode l, pnode r) {
    if (l && l -> swp)
        Turn(l);
    if (r && r -> swp)
        Turn(r);
    if (!l || !r)
        p = l ? l : r;
    else if (abs(rand() % (l -> s + r -> s)) < l -> s) {
        Merge(l -> r, l -> r, r);
        p = l;
    }
    else {
        Merge(r -> l, l, r -> l);
        p = r;
    }
    p -> s = Count(p -> l) + Count(p -> r) + 1;
}

void Print(pnode p) {
    if (p && p -> swp)
        Turn(p);
    if (!p) return;
    Print(p -> l);
    cout << p -> k << " ";
    Print(p -> r);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, Q, x;
    cin >> N >> Q;

    pnode root = nullptr, l, r;
    for (int i = 1; i <= N; i++)
        Merge(root, root, new node(i));

    while (Q--) {
        cin >> x;
        Split(root, x - 1, l, r);
        if (r)
            Turn(r);
        Merge(root, l, r);
    }

    Print(root);
}
