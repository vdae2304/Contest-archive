/*
ID: vdae_231
PROG: holstein
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

struct pos {
    int total[25], i;
    vector<int> sc;
};

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("holstein.in");
    ofstream cout("holstein.out");
    int V, G;

    cin >> V;
    int req[V];
    for (int i = 0; i < V; i++)
        cin >> req[i];

    cin >> G;
    int scoop[G][V];
    for (int i = 0; i < G; i++)
        for (int j = 0; j < V; j++)
            cin >> scoop[i][j];

    pos q; q.i = -1;
    memset(q.total, 0, sizeof(q.total));

    queue <pos> c;
    c.push(q);

    while (!c.empty()) {
        q = c.front();
        c.pop();

        bool solved = true;
        for (int i = 0; solved && i < V; i++)
            if (q.total[i] < req[i])
                solved = false;

        if (solved) {
            cout << q.sc.size();
            for (int i = 0; i < q.sc.size(); i++)
                cout << " " << q.sc[i];
            cout << "\n";
            return 0;
        }
        else {
            for (int i = q.i + 1; i < G; i++) {
                pos p = q; p.i = i;
                p.sc.push_back(i + 1);
                for (int j = 0; j < V; j++)
                    p.total[j] += scoop[i][j];
                c.push(p);
            }
        }
    }
}
