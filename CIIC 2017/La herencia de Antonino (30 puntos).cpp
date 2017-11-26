#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000

struct rect {
    int a, b, x, y;
};

int F, P, H, X, Y;
rect NR[MAXN], ND[MAXN], HE[MAXN];

bool Interseccion(rect A, rect B) {
    if (A.a < B.a)
        return Interseccion(B, A);
    return (B.a <= A.a && A.a < B.x) && ((A.b <= B.b && B.b < A.y) || (B.b <= A.b && A.b < B.y));
}

bool Contiene(rect A, rect B) {
    return A.a <= B.a && B.x <= A.x && A.b <= B.b && B.y <= A.y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> F >> P >> H >> X >> Y;

    for (int i = 0; i < F; i++)
        cin >> NR[i].a >> NR[i].b >> NR[i].x >> NR[i].y;
    for (int i = 0; i < P; i++)
        cin >> ND[i].a >> ND[i].b >> ND[i].x >> ND[i].y;
    for (int i = 0; i < H; i++)
        cin >> HE[i].a >> HE[i].b >> HE[i].x >> HE[i].y;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < F; j++)
            if (Interseccion(HE[i], NR[j]))
                cout << "F " << j + 1 << " ";

        for (int j = 0; j < P; j++)
            if (Interseccion(HE[i], ND[j]) && !Contiene(HE[i], ND[j]))
                cout << "P " << j + 1 << " ";

        for (int j = 0; j < H; j++)
            if (j != i && Interseccion(HE[i], HE[j]))
                cout << "H " << j + 1 << " ";

        cout << "\n";
    }
}
