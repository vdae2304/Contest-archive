#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    lld n, Ax, Ay, Bx, By, Cx, Cy;
    cin >> n >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    /*Check they are on the same quadrant*/
    if ((Bx - Ax)*(Cx - Ax) > 0 && (By - Ay)*(Cy - Ay) > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
