#include <iostream>
#include <vector>
using namespace std;
#define maxn 200

int V, E;
vector<int> graph[maxn];
int bipartite, color[maxn], nvertices[2];

//Verifica si el grafo es bipartito y en caso afirmativo, calcula el numero 
//de vertices por cada color.
void checkBipartite(int u) {
    nvertices[color[u]]++;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            checkBipartite(v);
        }
        else if (color[v] == color[u])
            bipartite = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E;

        //Reinicia el grafo.
        bipartite = true;
        for (int i = 0; i < V; ++i) {
            graph[i].clear();
            color[i] = -1;
        }

        //Lee el grafo.
        while (E--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        //Cada vertice tiene dos opciones: tiene un guardia o no. Puesto que
        //cada arista es vigilada por exactamente un guardia, no hay veritces del
        //mismo tipo adyacentes, es decir, el grafo debe ser bipartito.
        int ans = 0;
        for (int i = 0; i < V; ++i) 
            if (color[i] == -1) {
                nvertices[0] = 0;
                nvertices[1] = 0;

                color[i] = 0;
                checkBipartite(i);

                //Si el grafo es bipartito, tomamos la clase con menor numero de vertices.
                if (bipartite)
                    ans += max(1, min(nvertices[0], nvertices[1]));
                else
                    ans = -1;
            }

        //Imprime la respuesta.
        cout << ans << '\n';
    }

    return 0;
}