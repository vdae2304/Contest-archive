#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

typedef complex<long double> point;
#define x real()
#define y imag()

const double PI  = acos(-1);

//Producto cruz de dos vectores.
long double cross(point v, point w) {
    return (conj(v) * w).y;
}

//Rota un vector el angulo especificado.
point rotate(point v, long double angle = PI/2) {
    return polar(1.0L, angle) * v;
}

//Regresa el punto de interseccion de dos rectas.
point linelineintersection(point A, point B, point C, point D) {
    point v = B - A, w = D - C;
    return A + (cross(C - A, w)/cross(v, w)) * v;
}

//Regresa el circuncentro de un triangulo.
point circumcenter(point A, point B, point C) {
    point Mc = (A + B) / 2.0L, Ma = (B + C) / 2.0L;
    return linelineintersection(Mc, Mc + rotate(B - A), Ma, Ma + rotate(C - B));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n, ncase = 1;
    point P[50];
    
    while (cin >> n, n != 0) {
        //Lee los primeros tres puntos.
        for (int i = 0; i < 3; ++i) {
            long double px, py;
            cin >> px >> py;
            P[i] = point(px, py);
        }

        //Encuentra la circunferencia que pasa por los 3 puntos y apartir de esta encuentra 
        //los n vertices del poligono.
        point O = circumcenter(P[0], P[1], P[2]);
        long double angle = 2*PI / n;
        for (int i = 1; i < n; ++i)
            P[i] = O + rotate(P[0] - O, i*angle);

        //Encuentra las dimensiones de la caja.
        long double minx = P[0].x, maxx = P[0].x, miny = P[0].y, maxy = P[0].y;
        for (int i = 0; i < n; ++i) {
            minx = min(minx, P[i].x);
            maxx = max(maxx, P[i].x);
            miny = min(miny, P[i].y);
            maxy = max(maxy, P[i].y);
        }

        //Imprime la respuesta.
        cout << "Polygon " << ncase++ << ": " << fixed << setprecision(3) << (maxx - minx)*(maxy - miny) << '\n';
    }

    return 0;
}