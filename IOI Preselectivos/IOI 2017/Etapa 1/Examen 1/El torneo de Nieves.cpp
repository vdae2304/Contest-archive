#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;

ulli calcular(ulli i, ulli j) {
    return j * ((1ull << i) - 1) + j * (j - 1) / 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ulli N;
    cin >> N;

    vector<ulli> answer;
    for (int i = 0; i < 64; i++) {
        ulli low = 0, high = LLONG_MAX / (1ull << i);

        for (int r = 0; r < 64; r++) {
            ulli mid = (low + high) / 2, j = 2 * mid + 1;
            ulli x = calcular(i, j);

            if (x == N) {
                answer.push_back((1ull << i) * j);
                break;
            }
            else if (x > N)
                high = mid;
            else
                low = mid + 1;
        }
    }

    if (answer.empty())
        cout << "-1";
    else {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << "\n";
    }
}
