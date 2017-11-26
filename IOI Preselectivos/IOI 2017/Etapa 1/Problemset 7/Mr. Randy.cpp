#include <bits/stdc++.h>
using namespace std;

long long N, v[12];
bool usado[12];
vector<vector<long long> > solution;

void subconjunto(int i) {
    if (i >= N) {
        vector<long long> w;
        for (int j = 0; j < N; j++)
            if (usado[j])
                w.push_back(v[j]);
        solution.push_back(w);
    }
    else {
        subconjunto(i + 1);
        usado[i] = true;
        subconjunto(i + 1);
        usado[i] = false;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    subconjunto(0);
    sort(solution.begin(), solution.end());

    for (int i = 1; i < solution.size(); i++)
        if (solution[i] != solution[i - 1]) {
            cout << "\n";
            for (int j = 0; j < solution[i].size(); j++)
                cout << solution[i][j] << " ";
        }
}
