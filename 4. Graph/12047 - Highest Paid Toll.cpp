#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
#define maxn 100001

int N, M, s, t, p;
int vis[maxn], dist[2][maxn];
vector< pair<int, int> > graph[2][maxn];

//Algoritmo de Dijkstra para encontrar la distancia mas corta desde s (o t) a todos
//los demas vertices.
void Dijkstra(int source) {
    bool k = (source == t);
    fill_n(vis, N + 1, false);
    fill_n(dist[k], N + 1, 1e9);

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, source));
    dist[k][source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (!vis[u]) 
            for (int i = 0; i < graph[k][u].size(); ++i) {
                int v = graph[k][u][i].first, d = dist[k][u] + graph[k][u][i].second;
                if (d < dist[k][v]) {
                    dist[k][v] = d;
                    pq.push(make_pair(-d, v));
                }
            }

        vis[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M >> s >> t >> p;

        //Reinicia el grafo.
        for (int k = 0; k < 2; ++k)
            for (int i = 1; i <= N; ++i)
                graph[k][i].clear();

        //Guardamos el grafo y grafo transpuesto.
        while (M--) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[0][u].push_back(make_pair(v, c));
            graph[1][v].push_back(make_pair(u, c));
        }

        //Calcula la distancia mas corta desde s y desde t. Luego, probamos
        //todas las aristas (u, v): si la distancia de s a t pasando por (u, v)
        //no supera el limite p, actualizamos el mayor peso visto hasta ahora.
        int ans = -1;
        Dijkstra(s);
        Dijkstra(t);
        for (int u = 1; u <= N; ++u) 
            for (int i = 0; i < graph[0][u].size(); ++i) {
                int v = graph[0][u][i].first, c = graph[0][u][i].second;
                if (dist[0][u] + c + dist[1][v] <= p) 
                    ans = max(ans, c);
            }

        cout << ans << '\n';
    }

    return 0;
}