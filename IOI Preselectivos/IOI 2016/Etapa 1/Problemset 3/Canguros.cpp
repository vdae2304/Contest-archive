#include <bits/stdc++.h>
using namespace std;
main() {
    int C, N, M;
    scanf("%d %d", &C, &N);

    queue<int> canguros;
    for (int i = 0; i < N; i++) {
        char x;
        scanf("\n%c ", &x);
        switch (x) {
        case 'N':
            scanf("%d", &M);
            canguros.push(M + 1);
            break;
        case 'A':
            C -= canguros.front();
            canguros.pop();
            break;
        case 'C':
            printf("%d\n", canguros.size());
            break;
        case 'R':
            printf("%d\n", C);
        }
    }
}
