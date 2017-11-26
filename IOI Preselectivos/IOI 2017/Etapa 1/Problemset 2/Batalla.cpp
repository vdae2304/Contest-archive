#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    cin >> N;
    
    int Cartas[N], Lira[N];
    for (int i = 0; i < N; i++)
        cin >> Cartas[i];
    for (int i = 0; i < N; i++)
        cin >> Lira[i];
    
    sort(Cartas, Cartas + N);
    sort(Lira, Lira + N);
    int i = N - 1, j = N - 1, S = 0;
    while (i >= 0 && j >= 0) {
        if (Cartas[i] > Lira[j]) {
            S += Cartas[i];
            i--;
        }
        j--;
    }
    
    cout << S;
}
