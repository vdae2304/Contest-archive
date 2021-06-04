#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string apps;
vector<int> graph[260];

//Algoritmo de Kuhn para encontrar el emparejamiento maximo de un grafo bipartito.
int vis[260], match[10];

bool DFS(int u) {
    if (!vis[u]) {
        vis[u] = true;
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if (match[v] == -1 || DFS(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_matching() {
    int size = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < apps.size(); ++i) {
        memset(vis, false, sizeof vis);
        if (DFS(i))
            size++;
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    string line;

    while (getline(cin, line)) {
        //Genera el grafo bipartito.
        apps.clear();
        while (line.size() > 2) {
            //Agregamos la aplicacion en el grafo tantas veces lo indique.
            for (int t = '0'; t < line[1]; ++t) {
                //Por cada vez que aparece, agregamos las computadoras que lo pueden correr.
                graph[apps.size()].clear();
                for (int i = 3; line[i] != ';'; ++i)
                    graph[apps.size()].push_back(line[i] - '0');
                apps.push_back(line[0]);
            }
            getline(cin, line);
        }

        //Imprime la respuesta. Verifica que todas las aplicaciones hayan sido emparejadas.
        if (max_matching() == apps.size()) {
            for (int i = 0; i < 10; ++i) {
                if (match[i] == -1)
                    cout << '_';
                else
                    cout << apps[match[i]];
            }
            cout << '\n';
        }
        else
            cout << "!\n";
    }
    return 0;
}