#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int A, B, N;
    cin >> A >> B >> N;

    queue<pair<int, int> > cola;
    bitset<10000> usado;
    cola.push(make_pair(1, 0));

    while (cola.front().first != N) {
        int a = cola.front().first * A;
        int b = cola.front().first / B;
        int c = cola.front().second + 1;
        cola.pop();

        if (a < 10000 && !usado[a]) {
            cola.push(make_pair(a, c));
            usado[a] = true;
        }
        if (!usado[b]) {
            cola.push(make_pair(b, c));
            usado[b] = true;
        }
    }

    cout << cola.front().second;
}
