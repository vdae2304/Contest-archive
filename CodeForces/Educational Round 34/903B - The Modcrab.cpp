#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int H1, A1, C1, H2, A2;
    cin >> H1 >> A1 >> C1 >> H2 >> A2;

    int nattacks = (H2 + A1 - 1) / A1;
    int npotions = 0;
    while (H1 <= (nattacks - 1) * A2) {
        npotions++;
        H1 += C1 - A2;
    }

    cout << npotions + nattacks << "\n";
    while (npotions--)
        cout << "HEAL\n";
    while (nattacks--)
        cout << "STRIKE\n";
    return 0;
}