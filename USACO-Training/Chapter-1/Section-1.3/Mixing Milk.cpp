/*
ID: vdae_231
PROG: milk
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

struct farmer {
    int P, A;
};

bool order(farmer a, farmer b) {
    return a.P < b.P;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("milk.in");
    ofstream cout("milk.out");
    int N, M;
    cin >> N >> M;

    farmer v[M];
    for (int i = 0; i < M; i++)
        cin >> v[i].P >> v[i].A;
    sort(v, v + M, order);

    int i = 0, cost = 0;
    while (N) {
        int q = min(N, v[i].A);
        cost += q * v[i++].P;
        N -= q;
    }

    cout << cost << "\n";
}
