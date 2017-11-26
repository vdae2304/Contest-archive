#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M, K;
    cin >> N >> M >> K;

    int fridge[N];
    for (int i = 0; i < N; i++)
        cin >> fridge[i];
    sort(fridge, fridge + N);

    pii store[M];
    for (int i = 0; i < M; i++) {
        cin >> store[i].first;
        store[i].second = i + 1;
    }
    sort(store, store + M);

    vector<int> v;
    for (int day = 0, i = 0, j = 0; i < N || j < M; day++) {
        int drank = 0;
        for (; i < N && fridge[i] == day; i++, drank++);
        if (drank > K) {
            cout << "-1\n";
            return 0;
        }
        for (; j < M && drank < K; j++)
            if (store[j].first >= day) {
                v.push_back(store[j].second);
                drank++;
            }
        for (; i < N && drank < K; i++, drank++);
    }

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
