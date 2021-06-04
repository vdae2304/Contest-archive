#include <iostream>
using namespace std;

int N, M;
string graph[256];
int awake[256];

//Regresa el numero de dias que tarda el cerebro en activarse, o -1 si nunca
//se activa.
int solve() {
    int nawake = 3;
    //Iteramos por cada dia.
    for (int days = 1; days <= N; ++days) {
        //Verifica si ya estan activas todas las areas.
        if (nawake == N)
            return days - 1;
        //Iteramos sobre cada area no activa.
        for (char c = 'A'; c <= 'Z'; ++c)
            if (awake[c] == 1e9) {
                //Contamos el numero de conexiones que ya estaban activas.
                int cont = 0;
                for (int i = 0; i < graph[c].size(); ++i)
                    if (awake[graph[c][i]] < days)
                        cont++;
                //Si son mas de tres, esta area se activa.
                if (cont >= 3) {
                    awake[c] = days;
                    nawake++;
                }
            }
    }
    //Si despues de N dias no se activaron todas, nunca lo haran.
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    while (cin >> N >> M) {
        //Reinicia el grafo.
        for (char c = 'A'; c <= 'Z'; ++c) {
        	awake[c] = 1e9;
            graph[c].clear();
        }
        
        //Construye el grafo.
        string s;
        cin >> s;
        for (int i = 0; i < 3; ++i)
            awake[s[i]] = 0;
        
        while (M--) {
        	cin >> s;
        	graph[s[0]].push_back(s[1]);
        	graph[s[1]].push_back(s[0]);
        }

        //Imprime la respuesta.
        int ans = solve();
        if (ans == -1)
            cout << "THIS BRAIN NEVER WAKES UP\n";
        else
            cout << "WAKE UP IN, " << ans << ", YEARS\n";
    }

    return 0;
}