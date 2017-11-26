#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    vector<int> v;
    while (N) {
        v.push_back(N % 60);
        N /= 60;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[i] / 10; j++)
            cout << "L";
        for (int j = 0; j < v[i] % 10; j++)
            cout << "I";
        if (i)
            cout << ".";
    }
}
