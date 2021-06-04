#include <iostream>
#include <complex>
#include <vector>
using namespace std;

typedef complex<long double> point;
#define x real()
#define y imag()

//Producto punto de dos vectores.
long double dot(point v, point w) {
    return (conj(v) * w).x;
}

//Rota un vector 90 grados.
point rotate90(point v) {
    return point(0.0, 1.0) * v;
}

//Regresa los centros de las circunferencias de radio r que pasan por dos puntos.
vector<point> circle2points(long double r, point A, point B) {
    vector<point> O;
    point M = (A + B) / 2.0L, v = rotate90(A - B);
    long double t = (r * r) / dot(v, v) - 0.25;
    if (t >= 0) {
        t = sqrt(t);
        O.push_back(M + t*v);
        O.push_back(M - t*v);
    }
    return O;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n;
    long double px, py, r;
    point P[100];
    
    while (cin >> n, n != 0) {
        //Lee los puntos y el radio.
        for (int i = 0; i < n; ++i) {
            cin >> px >> py;
            P[i] = point(px, py);
        }
        cin >> r;

        //Verifica si el poligono esta en el interior de una circunferencia de radio
        //r y que pasa por dos puntos del poligono.
        bool packed = false;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                vector<point> O = circle2points(r, P[i], P[j]);
                for (int k = 0; k < O.size(); ++k) {
                    bool inside = true;
                    for (int l = 0; l < n; ++l)
                        if (abs(P[l] - O[k]) > r + 1e-6) {
                            inside = false;
                            break;
                        }
                    if (inside)
                        packed = true;
                }
            }

        //Imprime la respuesta.
        if (packed)
            cout << "The polygon can be packed in the circle.\n";
        else 
            cout << "There is no way of packing that polygon.\n";
    }

    return 0;
}