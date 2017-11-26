#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define MAXN 1000007

int N, dX[] = {-1, 0, 0, 1}, dY[] = {0, -1, 1, 0};
char c, d[] = {'U', 'L', 'R', 'D'};
vector<pii> vis[MAXN];
pii P;

bool Find(pii p) {
    int Hash = abs(p.first * p.second - p.first ^ p.second) % MAXN;
    return find(vis[Hash].begin(), vis[Hash].end(), p) != vis[Hash].end();
}

void Insert(pii &p) {
    int Hash = abs(p.first * p.second - p.first ^ p.second) % MAXN;
    vis[Hash].push_back(p);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    Insert(P);
    while (N--) {
        cin >> c;
        int nxt = find(d, d + 4, c) - d;
        P = pii(P.first + dX[nxt], P.second + dY[nxt]);

        for (int i = 0; i < 4; i++)
            if (i != 3 - nxt && Find(pii(P.first + dX[i], P.second + dY[i]))) {
                cout << "N";
                return 0;
            }

        Insert(P);
    }

    cout << "S";
}
