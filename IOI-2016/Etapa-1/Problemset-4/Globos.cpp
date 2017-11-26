#include <bits/stdc++.h>
using namespace std;
main() {
    int N;
    stack<int> p;
    scanf("%d", &N);

    double x[N], r[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &x[i], &r[i]);

        while (!p.empty()) {
            r[i] = min(r[i], (x[i] - x[p.top()]) * (x[i] - x[p.top()]) / (4 * r[p.top()]));
            if (r[i] < r[p.top()])
                break;
            p.pop();
        }

        p.push(i);
    }

    for (int i = 0; i < N; i++)
        printf("%6f\n", r[i]);
}
