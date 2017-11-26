/*
ID: vdae_231
PROG: friday
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N, answer[7], currentDay;
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
    return (!(year % 4) && (year % 100 || !(year % 400)));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("friday.in");
    ofstream cout("friday.out");
    cin >> N;

    for (int i = 1900; i < 1900 + N; i++) {
        month[1] = isLeap(i) ? 29 : 28;
        for (int j = 0; j < 12; j++) {
            answer[currentDay]++;
            currentDay = (currentDay + month[j]) % 7;
        }
    }

    for (int i = 0; i < 7; i++) {
        cout << answer[i];
        if (i < 6)
            cout << " ";
    }
    cout << "\n";
}
