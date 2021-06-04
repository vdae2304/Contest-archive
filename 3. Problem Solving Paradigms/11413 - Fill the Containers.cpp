#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N, M;
    int milk[1000];

    while (cin >> N >> M) {
        for (int i = 0; i < N; ++i)
            cin >> milk[i];

        //Hacemos una busqueda binaria sobre la respuesta.
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            //Suponemos que todos los contenedores tienen capacidad m.
            //Contamos cuantos contenedores se requieren para vaciar la leche.
            int cont = 1;
            for (int i = 0, curr = 0; i < N; ++i) {
                if (milk[i] > m) {
                    cont = 1e9;
                    break;
                }
                if (curr + milk[i] > m) {
                    cont++;
                    curr = 0;
                }
                curr += milk[i];
            }

            //Si requerimos M contenedores o menos, la maxima capacidad es a lo
            //mas m. De lo contrario, la maxima capacidad debe ser mayor.
            if (cont <= M)
                r = m;
            else
                l = m + 1;
        }

        //Imprime la respuesta.
        cout << l << '\n';
    }

    return 0;
}