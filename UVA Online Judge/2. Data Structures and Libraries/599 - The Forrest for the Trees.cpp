#include <iostream>
#include <vector>
using namespace std;

vector<char> graph[256];
bool visited[256];

//Realiza una DFS y regresa el numero de vertices en el subarbol.
int DFS(int v) {
    int cont = 1;
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i)
        if (!visited[graph[v][i]])
            cont += DFS(graph[v][i]);
    return cont;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    while (T--) {
        //Reinicia el arbol.
        for (char i = 'A'; i <= 'Z'; ++i) {
            graph[i].clear();
            visited[i] = false;
        }

        //Crea el arbol.
        string s;
        while (cin >> s, s[0] != '*') {
            graph[s[1]].push_back(s[3]);
            graph[s[3]].push_back(s[1]);
        }
        cin >> s;

        //Realiza una DFS para cada vertice no visitado.
        int trees = 0, acorns = 0;
        for (int i = 0; i < s.size(); i += 2)
            if (!visited[s[i]]) {
                //Verifica en que categoria esta.
                if (DFS(s[i]) > 1)
                    trees++;
                else
                    acorns++;
            }

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}
