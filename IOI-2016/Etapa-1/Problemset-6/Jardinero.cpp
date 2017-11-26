#include <bits/stdc++.h>
using namespace std;

int N, M, total;
int Xi[4], Yi[4], Ti[4];
bool visitado[8][8], v2[8][8];

//Retorna el numero de casillas que son accesibles desde la meta
int sinVisitar(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M || visitado[i][j] || v2[i][j])
        return 0;
    v2[i][j] = true;
    return 1 + sinVisitar(i - 1, j) + sinVisitar(i, j - 1) + sinVisitar(i, j + 1) + sinVisitar(i + 1, j);
}

void Busqueda(int i, int j, int k, int t) {
    //Nos salimos del mapa o ya pasamos por aqui
    if (i < 0 || i >= N || j < 0 || j >= M || visitado[i][j])
        return;

    //Llegamos al final
    if (i == 0 && j == 1) {
        if (t == N * M) //En el tiempo adecuado
            total++;
        return;
    }

    //Llegamos a un escondite
    if (i == Xi[k] && j == Yi[k]) {
        if (t != Ti[k]) //En tiempo incorrecto
            return;
        k++;
    }
    //Checa si lograremos llegar al siguiente escondite
    else if (abs(i - Xi[k]) + abs(j - Yi[k]) + t > Ti[k])
        return;
    //Checa si no llegamos antes de tiempo a otro escondite
    else for (int l = k + 1; l < 3; l++)
        if (i == Xi[l] && j == Yi[l])
            return;

    //Checa si el mapa no se dividio en 2
    memset(v2, false, sizeof(v2));
    v2[i][j] = true;
    if (sinVisitar(0, 1) < N * M - t)
        return;

    //Nos movemos
    visitado[i][j] = true; //Lo marcamos como visitado
    Busqueda(i - 1, j, k, t + 1);
    Busqueda(i, j - 1, k, t + 1);
    Busqueda(i, j + 1, k, t + 1);
    Busqueda(i + 1, j, k, t + 1);
    visitado[i][j] = false; //Lo desmarcamos
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < 3; i++) {
        cin >> Xi[i] >> Yi[i];
        Ti[i] = ((i + 1) * N * M) / 4;
    }
    Xi[3] = 0; Yi[3] = 1; Ti[3] = N * M;

    Busqueda(0, 0, 0, 1);
    cout << total;
}
