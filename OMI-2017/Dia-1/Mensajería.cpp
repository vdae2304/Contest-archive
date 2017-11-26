#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, K;
    cin >> N >> K;

    int s = 0, max_x = 0, k = 0, x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x >= K)
            k++;
        else
            s += x;
        max_x = max(max_x, x);
    }

    if (k)
        cout << s + k * K;
    else
        cout << s - max_x + K;
}
