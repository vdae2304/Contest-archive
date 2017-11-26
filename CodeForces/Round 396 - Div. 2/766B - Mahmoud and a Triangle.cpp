#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;

    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);

    int a = 0, b = 1, c = 2;
    while (c < N) {
        if (a < b && b < c && v[a] + v[b] > v[c]) {
            cout << "YES\n";
            return 0;
        }
        else if (c <= b)
            c++;
        else if (b <= a)
            b++;
        else
            a++;
    }
    cout << "NO\n";
}
