#include <bits/stdc++.h>
using namespace std;

int D, N;
int P[500], U[500];
int answer[100000]; //stores the max value for weight <= i

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> D >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i] >> U[i];

    for (int i = 0; i < N; i++)
        for (int j = D; j; j--)
            if (j >= P[i]) //If we can insert it, we do it only if we get a better max
                answer[j] = max(answer[j], answer[j - P[i]] + U[i]);

    cout << answer[D];
}
