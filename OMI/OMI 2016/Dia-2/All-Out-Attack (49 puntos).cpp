#include <bits/stdc++.h>
using namespace std;

int N, K;
string P[4];
bool effective[4][50000]; //if i-member can defeat j-enemy

vector<int> l[4];
void Busqueda(int i, int E[4]) {
    if (i == N) {
        for (int j = 0; j < 4; j++) {
            cout << "\n" << l[j].size() << "\n";
            for (int r = 0; r < l[j].size(); r++)
                cout << l[j][r] + 1 << " ";
        }
        exit(0);
    }
    //Try for each member for which is vulnerable
    for (int j = 0; j < 4; j++) {
        if (effective[j][i] && E[j]) {
            E[j]--;
            l[j].push_back(i);
            Busqueda(i + 1, E);
            l[j].pop_back();
            E[j]++;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;

    int E[4];
    for (int i = 0; i < 4; i++) {
        cin >> P[i] >> E[i];
        E[i] /= K;
    }
    for (int i = 0; i < N; i++) {
        char v;
        cin >> v;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < P[j].size(); k++) {
                if (P[j][k] == v) {
                    effective[j][i] = true;
                    break;
                }
            }
        }
    }

    Busqueda(0, E);
}
