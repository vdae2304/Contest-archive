#include <bits/stdc++.h>
using namespace std;
main() {
    int N, Q;
    scanf("%d\n", &N);

    int v[N], inicio = 0, i_menor = 0, i_mayor = N - 1;
    for (int i = 0; i < N; i++)
        scanf("%d ", &v[i]);

    scanf("%d\n", &Q);
    for (int i = 0; i < Q; i++) {
        char c; int x;
        scanf("\n%c %d", &c, &x);
        if (c == 'M') {
            if (x == -1) {
                inicio--;
                if (inicio < i_menor)
                    inicio = i_mayor;
            }
            else {
                inicio++;
                if (inicio > i_mayor)
                    inicio = i_menor;
            }
        }
        else if (c == 'Q') {
            if (x == -1) {
                i_menor++;
                if (i_menor > inicio)
                    inicio++;
            }
            else {
                i_mayor--;
                if (i_mayor < inicio)
                    inicio = i_menor;
            }
        }
        else {
            if (v[i_menor] <= x && x <= v[i_mayor]) {
                int index, low = i_menor, high = i_mayor + 1;
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (v[mid] == x) {
                        index = mid;
                        break;
                    }
                    else if (v[mid] > x)
                        high = mid;
                    else
                        low = mid + 1;
                }
                if (inicio <= index)
                    printf("%d\n", index - inicio + 1);
                else
                    printf("%d\n", i_mayor - inicio + index - i_menor + 2);
            }
            else
                printf("No Laurencio\n");
        }
    }
}
