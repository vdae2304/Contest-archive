#include <bits/stdc++.h>
using namespace std;
main() {
    int N, cont = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        if (!(2 * N % i)) {
            double m = (2 * N - i * i + i) / (2.0 * i);
            if (m > 0) {
                if (m == int(m))
                    cont++;
            }
            else
                break;
        }

    cout << cont;
}
