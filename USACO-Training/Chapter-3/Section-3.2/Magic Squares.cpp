/*
ID: vdae_231
PROG: msquare
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

struct state {
    int v[8];
    string seq;
} init, goal;

bitset<90000000> used;
int T[3][8] = {{7, 6, 5, 4, 3, 2, 1, 0},
               {3, 0, 1, 2, 5, 6, 7, 4},
               {0, 6, 1, 3, 4, 2, 5, 7}};

int getInt(state &a) {
    int aux = 0;
    for (int i = 7, j = 1; i >= 0; i--, j *= 10)
        aux += j * a.v[i];
    return aux;
}

state Transform(state &a, int change) {
    state b = a;
    b.seq.push_back('A' + change);
    for (int i = 0; i < 8; i++)
        b.v[i] = a.v[T[change][i]];
    return b;
}

string BFS() {
    queue<state> q;
    q.push(init);
    used[getInt(init)] = true;

    while (getInt(q.front()) != getInt(goal)) {
        for (int i = 0; i < 3; i++) {
            state nxt = Transform(q.front(), i);
            if (!used[getInt(nxt)]) {
                q.push(nxt);
                used[getInt(nxt)] = true;
            }
        }
        q.pop();
    }

    return q.front().seq;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("msquare.in");
    ofstream cout("msquare.out");
    for (int i = 0; i < 8; i++) {
        cin >> goal.v[i];
        init.v[i] = i + 1;
    }
    string ans = BFS();
    cout << ans.size() << "\n" << ans << "\n";
}
