#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n;
    int energy[101];
    int path[101], dist[101];

    while (cin >> n, n != -1) {
        //Lee los datos de las habitaciones.
        vector< pair<int, int> > graph;
        for (int i = 1; i <= n; ++i) {
            int sz, j;
            cin >> energy[i] >> sz;
            
            while (sz--) {
                cin >> j;
                graph.push_back(make_pair(i, j));
            }

            path[i] = false;
            dist[i] = -1e9;
        }

        //Algoritmo de Bellman-Ford para encontrar el camino desde 1 hasta n que 
        //termine con la mayor cantidad de energia posible.
        path[n] = true;
        dist[1] = 100;

        for (int i = 0; i < n - 1; ++i) 
            for (int j = 0; j < graph.size(); ++j) {
                int u = graph[j].first, v = graph[j].second;
                if (path[v])
                    path[u] = true;
                if (dist[u] > 0 && dist[u] + energy[v] > dist[v]) 
                    dist[v] = dist[u] + energy[v];
            }
        
        bool pos_cycle = false;
        for (int j = 0; j < graph.size(); ++j) {
            int u = graph[j].first, v = graph[j].second;
            if (dist[u] > 0 && path[u] && dist[u] + energy[v] > dist[v]) 
                pos_cycle = true;
        }

        //Imprime la respuesta. Verifica que haya un camino desde 1 hasta n y este
        //camino finalice con energia positiva o exista en el camino un ciclo positivo.
        if (path[1] && (dist[n] > 0 || pos_cycle))
            cout << "winnable\n";
        else
            cout << "hopeless\n";
    } 

    return 0;
}