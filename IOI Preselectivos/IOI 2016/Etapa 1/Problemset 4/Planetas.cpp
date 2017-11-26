#include <bits/stdc++.h>
using namespace std;

int N;
double planetas[1000];

double fuerza(double M) {
    double F = 0;
    for (int i = 0; i < N; i++)
        F += 1 / (planetas[i] - M);
    return F;
}

double Busqueda(double a, double b) {
    for(int i = 0; i < 25; i++) {
        double m = (a + b) / 2;
	if (fuerza(m) > 0)
	    b = m;
    	else
	    a = m;
    }
    return a;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> planetas[i];
    sort(planetas, planetas + N);

    cout << N - 1 << endl << fixed << setprecision(3);
    for(int i = 0; i < N - 1; ++i)
        cout << Busqueda(planetas[i], planetas[i + 1]) << " ";
}
