#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T, K;
    cin >> T;

    while (T--) {
        char grid1[5][6], grid2[5][6], cmn[5][7];
        int sz[5];
        cin >> K;

        //Lee las cuadriculas y las guarda por columnas.
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> grid1[j][i];
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> grid2[j][i];

        //Encuentra los caracteres en comun por cada columna.
        int maxk = 1;
        for (int j = 0; j < 5; ++j) {
            sort(grid1[j], grid1[j] + 6);
            sort(grid2[j], grid2[j] + 6);
            sz[j] = set_intersection(grid1[j], grid1[j] + 6, grid2[j], grid2[j] + 6, cmn[j]) - cmn[j];
            sz[j] = unique(cmn[j], cmn[j] + sz[j]) - cmn[j];
            maxk *= sz[j];
        }

        //Imprime la respuesta.
        if (K-- > maxk)
            cout << "NO\n";
        else {
            string ans = "AAAAA";
            for (int j = 4; j >= 0; --j) {
                ans[j] = cmn[j][K % sz[j]];
                K /= sz[j];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}