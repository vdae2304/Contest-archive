#include <bits/stdc++.h>
using namespace std;

int N, Q;
int DP[255][11];
pair<string, char> op[36];

string operation(string s, int i) {
    s[s.size() - 1] = op[i].first[1];
    s.push_back(op[i].first[0]);
    return s;
}

int Busqueda(string l) {
    if (l.size() == N)
        return 1;
    if (DP[l[l.size() - 1]][l.size()])
        return DP[l[l.size() - 1]][l.size()];

    int S = 0;
    for (int i = 0; i < Q; i++)
        if (op[i].second == l[l.size() - 1])
            S += Busqueda(operation(l, i));
    return DP[l[l.size() - 1]][l.size()] = S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
        cin >> op[i].first >> op[i].second;
    cout << Busqueda("a");
}
