#include <bits/stdc++.h>
using namespace std;
#define MAXX 1000001

long long N, x;
bool no_primo[MAXX];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    no_primo[1] = true;
    for (long long i = 2; i < MAXX; i++)
        if (!no_primo[i])
            for (long long j = i * i; j < MAXX; j += i)
                no_primo[j] = true;

    while (N--) {
        cin >> x;
        long long sq = sqrt(x);
        if (sq * sq == x && !no_primo[sq])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
