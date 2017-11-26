#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;

map<ulli, ulli> DP;

ulli f(ulli N) {
    if (DP.find(N) == DP.end()) {
        if (N % 2)
            DP[N] = f(N / 2);
        else
            DP[N] = f(N / 2) + f(N / 2 - 1);
    }
    return DP[N];
}

main() {
    DP[0] = DP[1] = 1;
    ulli N;
    cin >> N;
    cout << f(N);
}
