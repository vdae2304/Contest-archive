#include <iostream>
#include <cstring>
using namespace std;
#define MAXS 1010
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    //Precalcula la respuesta. Para cada numero calcula la suma de sus divisores y
    //guarda el mayor numero que de esa suma.
    int ans[MAXS];
    memset(ans, -1, sizeof(ans));

    for (int n = 1; n < MAXS; ++n) {
        int S = 0, i;
        for (i = 1; i * i < n; ++i)
            if (n % i == 0)
                S += i + n/i;
        if (n == i * i)
            S += i;
        if (S < MAXS)
            ans[S] = n;
    }

    //Lee los casos.
    int S;
    cin >> S;
    for (int ncase = 1; S != 0; ++ncase) {
        cout << "Case " << ncase << ": " << ans[S] << '\n';
        cin >> S;
    }
    
    return 0;
}
