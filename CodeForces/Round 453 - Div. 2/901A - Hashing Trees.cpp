#include <bits/stdc++.h>
using namespace std;
#define MAXH 1000000

int H, A[MAXH];
int TreeA[MAXH], TreeB[MAXH];

bool checkOnes() {
    for (int i = 0; i < H; i++)
        if (A[i] != 1 && A[i + 1] != 1)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> H;

    for (int i = 0; i <= H; i++)
        cin >> A[i];

    if (checkOnes())
        cout << "perfect\n";
    else {
        int N = 1;
        cout << "ambiguous\n";

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= A[i]; j++) {
                TreeA[N + j] = N;
                TreeB[N + j] = N;
            }
            if (A[i - 1] != 1)
                TreeB[N + 1] = N - 1;
            N += A[i];
        }

        for (int i = 1; i <= N; i++)
            cout << TreeA[i] << " ";
        cout << "\n";
        for (int i = 1; i <= N; i++)
            cout << TreeB[i] << " ";
        cout << "\n";
    }

    return 0;
}
