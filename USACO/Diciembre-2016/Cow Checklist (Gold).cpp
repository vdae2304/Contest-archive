#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int H, G, DP[1001][1001][2];
pii Holsteins[1000], Guernseys[1000];

int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int Solve(int Hi, int Gi, bool breed, pii current) {
    if (Hi == H - 1 && Gi == G)
        return dist(current, Holsteins[Hi]);
    if (DP[Hi][Gi][breed] == -1) {
        DP[Hi][Gi][breed] = INFINITY;
        if (Hi < H - 1)
            DP[Hi][Gi][breed] = Solve(Hi + 1, Gi, 0, Holsteins[Hi]) + dist(current, Holsteins[Hi]);
        if (Gi < G)
            DP[Hi][Gi][breed] = min(DP[Hi][Gi][breed], Solve(Hi, Gi + 1, 1, Guernseys[Gi]) + dist(current, Guernseys[Gi]));
    }
    return DP[Hi][Gi][breed];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("checklist.in");
    ofstream cout("checklist.out");
    cin >> H >> G;

    for (int i = 0; i < H; i++)
        cin >> Holsteins[i].first >> Holsteins[i].second;
    for (int i = 0; i < G; i++)
        cin >> Guernseys[i].first >> Guernseys[i].second;

    memset(DP, -1, sizeof(DP));
    cout << Solve(1, 0, 0, Holsteins[0]) << "\n";
}
