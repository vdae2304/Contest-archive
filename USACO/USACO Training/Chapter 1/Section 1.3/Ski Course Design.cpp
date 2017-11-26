/*
ID: vdae_231
PROG: skidesign
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("skidesign.in");
    ofstream cout("skidesign.out");
    int N, answer = INFINITY;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i <= 83; i++) {
        int cost = 0;
        for (int j = 0; j < N; j++) {
            if (v[j] < i)
                cost += (i - v[j])*(i - v[j]);
            else if (v[j] > i + 17)
                cost += (17 + i - v[j])*(17 + i - v[j]);
        }
        answer = min(answer, cost);
    }

    cout << answer << "\n";
}
