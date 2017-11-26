#include <bits/stdc++.h>
using namespace std;

struct edificio {
   long long h, i;
};

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, area = 0;
    cin >> N;

    stack<edificio> p;
    for (int i = 0; i <= N; i++) {
        int altura = 0, j = i;

        if (i < N)
            cin >> altura;

        while (!p.empty() && p.top().h >= altura) {
            j = p.top().i;
            area = max(area, p.top().h * (i - j));
            p.pop();
        }

        p.push(edificio {altura, j});
    }

    cout << area;
}
