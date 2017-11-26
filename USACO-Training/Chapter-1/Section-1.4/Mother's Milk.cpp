/*
ID: vdae_231
PROG: milk3
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
bool solution[21], visited[21][21][21];

void solve(int a, int b, int c) {
    if (visited[a][b][c])
        return;
    visited[a][b][c] = true;

    if (!a)
        solution[c] = true;

    solve(a + min(A - a, b), b - min(A - a, b), c);
    solve(a + min(A - a, c), b, c - min(A - a, c));
    solve(a - min(B - b, a), b + min(B - b, a), c);
    solve(a, b + min(B - b, c), c - min(B - b, c));
    solve(a - min(C - c, a), b, c + min(C - c, a));
    solve(a, b - min(C - c, b), c + min(C - c, b));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");
   
    cin >> A >> B >> C;
    solve(0, 0, C);

    string s = "";
    for (int i = 0; i <= 20; i++)
        if (solution[i]) {
            cout << s << i;
            s = " ";
        }
    cout << "\n";
}
