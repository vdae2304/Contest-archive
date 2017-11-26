#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
typedef pair<int, int> pii;

int N, v[MAXN], cnt[4];
vector<pii> mov;

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    for (int i = 0, j = cnt[1], k = N - 1; i < cnt[1]; i++) {
        if (v[i] == 2) {
            for (; j < N && v[j] != 1; j++);
            swap(v[i], v[j]);
            mov.push_back(pii(i + 1, j + 1));
        }
        else if (v[i] == 3) {
            for (; k >= cnt[1] && v[k] != 1; k--);
            swap(v[i], v[k]);
            mov.push_back(pii(i + 1, k + 1));
        }
    }

    for (int i = cnt[1], j = cnt[1] + cnt[2]; i < cnt[1] + cnt[2]; i++)
        if (v[i] != 2) {
            for (; j < N && v[j] != 2; j++);
            swap(v[i], v[j]);
            mov.push_back(pii(i + 1, j + 1));
        }

    cout << mov.size() << "\n";
    for (int i = 0; i < mov.size(); i++)
        cout << mov[i].first << " " << mov[i].second << "\n";
}
