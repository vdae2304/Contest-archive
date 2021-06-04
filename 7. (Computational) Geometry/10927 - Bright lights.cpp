#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct point {
    int x, y, z;
    long double norm, arg;
};

//Compara dos puntos por su argumento y norma.
bool polar_cmp(point P, point Q) {
    if (abs(P.arg - Q.arg) < 1e-12)
        return P.norm < Q.norm;
    return P.arg < Q.arg;
}

//Compara dos puntos por sus coordenadas en x, y.
bool coord_cmp(point P, point Q) {
    if (P.x == Q.x)
        return P.y < Q.y;
    return P.x < Q.x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N;
    point P[100000];

    int ncase = 1;
    while (cin >> N, N != 0) {
        //Lee los puntos y los ordena en base a su argumento y norma.
        for (int i = 0; i < N; ++i) {
            cin >> P[i].x >> P[i].y >> P[i].z;
            P[i].norm = hypot(P[i].x, P[i].y);
            P[i].arg = atan2(P[i].y, P[i].x);
        }
        sort(P, P + N, polar_cmp);

        //Busca aquellos puntos que no sean visibles.
        vector<point> ans;
        for (int i = 0, j; i < N; i = j) {
            for (j = i; j < N && P[j].arg < P[i].arg + 1e-12; ++j);
            for (int k = i, maxz = -1; k < j; ++k) {
                if (maxz >= P[k].z)
                    ans.push_back(P[k]);
                else
                    maxz = P[k].z;
            }
        }
        sort(ans.begin(), ans.end(), coord_cmp);

        //Imprime la respuesta.
        cout << "Data set " << ncase++ << ":\n";
        if (ans.empty()) 
            cout << "All the lights are visible.\n";
        else {
            cout << "Some lights are not visible:\n";
            for (int i = 0; i < ans.size() - 1; ++i)
                cout << "x = " << ans[i].x << ", y = " << ans[i].y << ";\n";
            cout << "x = " << ans.back().x << ", y = " << ans.back().y << ".\n";
        }
    }

    return 0;
}