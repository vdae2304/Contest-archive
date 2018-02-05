#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define MAXN 2000000

int N, dX[] = {-1, 0, 0, 1}, dY[] = {0, -1, 1, 0};
char c, d[] = {'U', 'L', 'R', 'D'};
pii P;

struct Hash {
    size_t operator()(const pii &p) const {
        return abs(p.first * p.second - ~(p.second ^ p.first)) % MAXN;
    }
};
unordered_set<pii, Hash> vis(MAXN);

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    vis.insert(P);

    while (N--) {
        cin >> c;
        int nxt = find(d, d + 4, c) - d;
        P = pii(P.first + dX[nxt], P.second + dY[nxt]);

        for (int i = 0; i < 4; i++)
            if (i != 3 - nxt && vis.count(pii(P.first + dX[i], P.second + dY[i]))) {
                cout << "N";
                return 0;
            }

        vis.insert(P);
    }

    cout << "S";
}
