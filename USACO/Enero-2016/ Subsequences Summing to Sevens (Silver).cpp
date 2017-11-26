#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    int N, r = 0, sumaActual = 0;
    cin >> N;

    int menor[7], mayor[7] = {}, aux;
    fill(menor, menor + 7, INFINITY);

    for (int i = 0; i < N; i++) {
        cin >> aux;
        sumaActual = (sumaActual + aux) % 7;
        menor[sumaActual] = min(i, menor[sumaActual]);
        mayor[sumaActual] = i;
    }

    for (int i = 0; i < 7; i++)
        r = max(r, mayor[i] - menor[i]);
    cout << r;
}
