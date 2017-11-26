#include <iostream>
using namespace std;

int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N;
    unsigned long long t, u = 0;
    cin >> N >> t;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            u++;
        else {
            if (a < b)
                swap(a, b);
            u += b / mcd(a, b) + 1;
        }
    }

    if (--u < t)
        cout << u;
    else
        cout << "El Agente A no sera heroe nacional, el Doctor B destruira su pais";
}
