#include <bits/stdc++.h>
using namespace std;

int N, vis[100], match[100];
char v[100];
vector<int> adj[100];

bool DFS(int x) {
    if (vis[x]) return false;
    vis[x] = true;
    for (int a : adj[x])
        if (match[a] == -1 || DFS(match[a])) {
            match[a] = x;
            return true;
        }
    return false;
}

int Kuhn() {
    int sz = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < N; i++) {
        memset(vis, false, sizeof vis);
        if (DFS(i))
            sz++;
    }
    return sz;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    while (getline(cin, s)) {
        N = 0;
        for (int i = 0; i < 100; i++)
            adj[i].clear();

        while (s.size()) {
            stringstream ss(s);
            char c; int x; string y;
            ss >> c >> x >> y;

            for (int i = 0; i < x; i++) {
                v[N++] = c;
                for (int j = 0; j < y.size() - 1; j++)
                    adj[N - 1].push_back(y[j] - '0');
            }

            getline(cin, s);
        }

        if (Kuhn() != N)
            cout << "!";
        else for (int i = 0; i < 10; i++) {
            if (match[i] == -1)
                cout << "_";
            else
                cout << v[match[i]];
        }
        cout << "\n";
    }
}
