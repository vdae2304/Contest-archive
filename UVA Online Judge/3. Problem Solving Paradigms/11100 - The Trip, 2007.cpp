#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n;
    int bag[10000];

    cin >> n;
    while (n != 0) {
        //Lee las maletas y las ordena.
        for (int i = 0; i < n; ++i) 
            cin >> bag[i];
        sort(bag, bag + n);

        //El numero de maletas al final sera igual al mayor numero de maletas iguales.
        int nbags = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            for (; j < n && bag[i] == bag[j]; ++j);
            nbags = max(nbags, j - i);
        }
        
        //Imprime la respuesta.
        cout << nbags << '\n';
        for (int i = 0; i < nbags; ++i) {
            //Distribuimos las maletas equitativamente segun su indice modulo nbags.
            cout << bag[i];
            for (int j = i + nbags; j < n; j += nbags)
                cout << ' ' << bag[j];
            cout << '\n';
        }

        //Lee el siguiente caso.
        cin >> n;
        if (n != 0)
            cout << '\n';
    }

    return 0;
}