#include <bits/stdc++.h>
using namespace std;
main() {
    int N, radio[7] = {0, 580, 980, 1190, 1250, 1420, 2000};
    cin >> N;

    if (N < 540 || N > 1520)
        cout << "error";
    else
        for (int i = 0; i < 6; i++)
            if (radio[i] <= N && N <= radio[i + 1]) {
                if (N - radio[i] < radio[i + 1] - N)
                    cout << "atras " << N - radio[i];
                else
                    cout << "adelante " << radio[i + 1] - N;
            }
}
