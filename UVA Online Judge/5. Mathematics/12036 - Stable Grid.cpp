#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, n, Gij;
    cin >> T;

    for (int ncase = 1; ncase <= T; ++ncase) {
        cin >> n;

        int cont[101] = {};
        string stable = "yes";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> Gij;
                cont[Gij]++;
                //Principio de las Casillas: Si algun elemento aparece mas de
                //n veces, entonces se repetira en alguna columna.
                if (cont[Gij] > n)
                    stable = "no";
            }

        cout << "Case " << ncase << ": " << stable << '\n';
    }
    
    return 0;
}