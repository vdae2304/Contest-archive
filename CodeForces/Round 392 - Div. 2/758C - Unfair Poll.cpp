#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M, X, Y;
    long long K, minQ, maxQ, Sergei;
    cin >> N >> M >> K >> X >> Y;

    if (N == 1) {
        minQ = K / M;
        maxQ = (K + M - 1) / M;
        Sergei = (Y <= K % M) ? maxQ : minQ;
    }
    else {
        long long num_vueltas = (K / M - 1) / (N - 1);
        K -= M * (num_vueltas * (N - 1) + bool(num_vueltas));

        minQ = (num_vueltas + 1) / 2;
        maxQ = ((N > 2) ? num_vueltas : minQ) + bool(K);

        if (X == 1)
            Sergei = (num_vueltas + 2) / 2;
        else if (X == N)
            Sergei = (num_vueltas + 1) / 2;
        else
            Sergei = num_vueltas;

        if ((num_vueltas % 2 && X < N && M * (N - 1 - X) + Y <= K) ||
            (!(num_vueltas % 2) && X > 1 && (num_vueltas ? 0 : M) + M * (X - 2) + Y <= K))
            Sergei++;
    }

    cout << maxQ << " " << minQ << " " << Sergei << "\n";
}
