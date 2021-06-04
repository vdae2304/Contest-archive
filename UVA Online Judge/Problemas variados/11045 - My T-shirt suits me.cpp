#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> adj[60];
string vsize, tsize[6] = {"XXL", "XL", "L", "M", "S", "XS"};

int match[60];
bool vis[60];

bool Dfs(int x) {
    if (vis[x])
        return false;
    vis[x] = true;
    for (int a : adj[x])
        if (match[a] == -1 || Dfs(match[a])) {
            match[a] = x;
            return true;
        }
    return false;
}

int Kuhn() {
    int sz = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < M; i++) {
        memset(vis, false, sizeof vis);
        if (Dfs(i))
            sz++;
    }
    return sz;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (int i = 0; i < M; i++) {
             adj[i].clear();
            for (int j = 0; j < 2; j++) {
                cin >> vsize;
                int k = find(tsize, tsize + 6, vsize) - tsize;
                for (int r = 0; r < N; r += 6)
                    adj[i].push_back(r + k);
            }
        }

        if (Kuhn() == M)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
