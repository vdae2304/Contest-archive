/*
ID: vdae_231
PROG: milk2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
bool milking[1000000];
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");
    int N, a, b, start = INFINITY, ending = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++)
            milking[j]++;
        start = min(start, a);
        ending = max(ending, b);
    }

    int time1 = 0, time2 = 0;
    a = b = 0;
    for (int i = start; i < ending; i++) {
        if (milking[i]) {
            a++;
            b = 0;
        }
        else {
            b++;
            a = 0;
        }
        time1 = max(time1, a);
        time2 = max(time2, b);
    }
    cout << time1 << " " << time2 << "\n";
}
