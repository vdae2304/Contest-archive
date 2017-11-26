#include <bits/stdc++.h>
using namespace std;

int N, P[32];
long long menor = INFINITY;
vector<pair<int, long long>> A, B;

void cuenta(long long S1, long long S2, int i, int cont) {
    if (i >= N / 2) {
        A.push_back(make_pair(cont, S1));
        B.push_back(make_pair(cont, S2));
    }
    else {
        cuenta(S1 - P[i], S2 - P[i + N / 2], i + 1, cont);
        cuenta(S1 + P[i], S2 + P[i + N / 2], i + 1, cont + 1);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> P[i];

    cuenta(0, 0, 0, 0);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        auto j = lower_bound(B.begin(), B.end(), make_pair(N / 2 - A[i].first, -A[i].second));
        if (j != B.end())
            menor = min(menor, abs(A[i].second + j -> second));
    }

    cout << menor;
}
