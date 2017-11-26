#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K, X;
    cin >> N >> K >> X;

    int bucket[1025] = {}, ranger;
    for (int i = 0; i < N; i++) {
        cin >> ranger;
        bucket[ranger]++;
    }

    while (K--) {
        int aux[1025] = {}, ind = 0;
        for (int i = 0; i < 1025; i++) {
            aux[i] += bucket[i] / 2;
            aux[i ^ X] += bucket[i] / 2;
            if (bucket[i] % 2) {
                aux[i] += ind % 2;
                aux[i ^ X] += !(ind % 2);
            }
            ind += bucket[i];
        }
        memcpy(bucket, aux, sizeof bucket);
    }

    int maxr, minr;
    for (minr = 0; !bucket[minr]; minr++);
    for (maxr = 1024; !bucket[maxr]; maxr--);

    cout << maxr << " " << minr;
}
