#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 1000

struct edge {
    int u, v, w;
};

//Compara dos aristas por su peso.
bool cmp_by_weight(edge e1, edge e2) {
    return e1.w < e2.w;
}

int n, r;
int x[maxn], y[maxn];
vector<edge> graph;

//Union-Find por rango y compresion de camino.
int p[maxn], h[maxn];

int Find(int u) {
    if (p[u] != u)
        p[u] = Find(p[u]);
    return p[u];
}

void Union(int u, int v) {
    int a = Find(u), b = Find(v);
    if (h[a] < h[b]) 
        p[a] = b;
    else {
        p[b] = a;
        if (h[a] == h[b])
            h[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    for (int ncase = 1; ncase <= T; ++ncase) {
    	//Lee los puntos.
        cin >> n >> r;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            p[i] = i;
            h[i] = 0;
        }

        //Crea un grafo completo donde el peso de cada arista es la distancia entre los puntos.
        graph.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                graph.push_back(edge{i, j, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])});
        sort(graph.begin(), graph.end(), cmp_by_weight);

        //Algoritmo de Kruskal para encontrar el arbol de expansion minima.
        int nstates = 1;
        double road = 0, railroad = 0;
        for (int i = 0; i < graph.size(); ++i) 
            if (Find(graph[i].u) != Find(graph[i].v)) {
                Union(graph[i].u, graph[i].v);

                //Verifica si estan en el mismo estado o no.
                if (graph[i].w <= r * r)
                    road += sqrt(graph[i].w);
                else {
                    railroad += sqrt(graph[i].w);
                    nstates++;
                }
            }

        //Imprime la respuesta.
        cout << "Case #" << ncase << ": " << nstates << " " << round(road) << " " << round(railroad) << "\n";
    }

    return 0;
}