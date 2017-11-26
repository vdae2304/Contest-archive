/*
ID: vdae_231
PROG: transform
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N;
struct board {
    char C[10][10];
};

board rot(board a) {
    board b;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b.C[j][N - i - 1] = a.C[i][j];
    return b;
}

board re(board a) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N / 2; j++)
            swap(a.C[i][j], a.C[i][N - j - 1]);
    return a;
}

bool eq(board a, board b) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a.C[i][j] != b.C[i][j])
                return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("transform.in");
    ofstream cout("transform.out");
    cin >> N;

    board a[2];
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> a[k].C[i][j];

    if (eq(a[1], rot(a[0])))
        cout << "1\n";
    else if (eq(a[1], rot(rot(a[0]))))
        cout << "2\n";
    else if (eq(a[1], rot(rot(rot(a[0])))))
        cout << "3\n";
    else if (eq(a[1], re(a[0])))
        cout << "4\n";
    else if (eq(a[1], rot(re(a[0]))) || eq(a[1], rot(rot(re(a[0])))) || eq(a[1], rot(rot(rot(a[0])))))
        cout << "5\n";
    else if (eq(a[1], a[0]))
        cout << "6\n";
    else
        cout << "7\n";
}
