#include <bits/stdc++.h>
using namespace std;
main() {
    int N, a = 1, b = 2;
    cin >> N;
    for (int i = 1; i < N; i++) {
        if (i != a)
            cout << i << " ";
        else {
            a += b;
            swap(a, b);
        }
    }
}
