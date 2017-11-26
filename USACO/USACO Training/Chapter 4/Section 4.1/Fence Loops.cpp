/*
ID: vdae_231
PROG: fence6
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXV 201
typedef pair<int, int> pii;

int N, M, ans = INFINITY;
bool visited[MAXV];
vector<pii> graph[MAXV];

void perimeter(int current, int origin, int previous, int total) {
    visited[current] = true;
    for (pii nxt : graph[current]) {
        if (nxt.first == origin && nxt.first != previous)
            ans = min(ans, total + nxt.second);
        else if (!visited[nxt.first] && total + nxt.second < ans)
            perimeter(nxt.first, origin, current, total + nxt.second);
    }
    visited[current] = false;
}

int node[MAXV][2];
vector<int> P[MAXV][2];

int getNode(int id, int aux) {
    for (int i : P[id][aux])
        for (int j = 0; j < 2; j++)
            for (int k : P[i][j])
                if (k == id)
                    return node[i][j];
    return M++;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("fence6.in");
    ofstream cout("fence6.out");
    cin >> N;

    for (int i = 0; i < N; i++) {
        int id, len, Ns[2], nxt;
        cin >> id >> len >> Ns[0] >> Ns[1];

        for (int j = 0; j < 2; j++)
            while (Ns[j]--) {
                cin >> nxt;
                P[id][j].push_back(nxt);
            }

        node[id][0] = getNode(id, 0);
        node[id][1] = getNode(id, 1);

        graph[node[id][0]].push_back(pii(node[id][1], len));
        graph[node[id][1]].push_back(pii(node[id][0], len));
    }

    for (int i = 0; i < M; i++)
        perimeter(i, i, 0, 0);
    cout << ans << "\n";
}
