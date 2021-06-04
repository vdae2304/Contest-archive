#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

string var;
vector<string> toposort;
bool smaller[256][256], added[20];

//Genera todos los posibles ordenes topologicos.
void solve(string order = "") {
    if (order.size() == var.size())
        toposort.push_back(order);
    else {
        //Prueba agregando cada variable una por una.
        for (int i = 0; i < var.size(); ++i)
            if (!added[i]) {
                //Verifica que no haya otra variable sin agregar que sea menor.
                bool ok = true;
                for (int j = 0; j < var.size(); ++j)
                    if (i != j && !added[j] && smaller[var[j]][var[i]])
                        ok = false;
                //Agrega la variable y procede recursivamente.
                if (ok) {
                    added[i] = true;
                    solve(order + var[i]);
                    added[i] = false;
                }
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    string tmp;
    cin >> T;
    getline(cin, tmp);

    while (T--) {
        //Reinicia las variables.
        var = "";
        memset(smaller, false, sizeof smaller);
        memset(added, false, sizeof added);
        toposort.clear();

        //Lee la lista de variables.
        getline(cin, tmp);
        getline(cin, tmp);
        stringstream in = stringstream(tmp);
        while (in >> tmp) 
            var.push_back(tmp[0]);
        sort(var.begin(), var.end());

        //Lee la lista de desigualdades.
        getline(cin, tmp);
        in = stringstream(tmp);
        while (in >> tmp) 
            smaller[tmp[0]][tmp[2]] = true;
        
        //Genera toda la lista de desigualdades por transitividad.
        for (int k = 0; k < var.size(); ++k)
            for (int i = 0; i < var.size(); ++i)
                for (int j = 0; j < var.size(); ++j)
                    if (smaller[var[i]][var[k]] && smaller[var[k]][var[j]])
                        smaller[var[i]][var[j]] = true;

        //Imprime la respuesta.
        solve();
        if (toposort.empty())
            cout << "NO\n";
        else {
            for (int i = 0; i < toposort.size(); ++i) {
                cout << toposort[i][0];
                for (int j = 1; j < toposort[i].size(); ++j)
                    cout << ' ' << toposort[i][j];
                cout << '\n';
            }
        }

        if (T)
            cout << '\n';
    }

    return 0;
}