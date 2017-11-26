#include <bits/stdc++.h>
using namespace std;
#define MAXN 3010
typedef pair<int, int> pii;

int N, K, ans, p[MAXN], maxp[MAXN];
bool vis[MAXN][MAXN];

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> p[i];

    for (int i = N - 1; i >= 0; i--)
        maxp[i] = max(p[i], maxp[i + 1]);

    queue<pii> q;
    q.push(pii(0, 1));
    K++;

    while (K--) {
        int l = q.size();
        while (l--) {
            pii curr = q.front();
            q.pop();

            if (!vis[curr.first][curr.second]) {
                vis[curr.first][curr.second] = true;
                ans++;

                if (curr.second < N) {
                    if (maxp[curr.second] <= 1 && p[curr.first] <= 1)
                        q.push(pii(curr.first, curr.second));
                    if (maxp[curr.second] >= 1 && p[curr.first] <= 1)
                        q.push(pii(curr.second, curr.second + 1));
                    if (maxp[curr.second] <= 1 && p[curr.first] >= 1)
                        q.push(pii(curr.first, curr.second + 1));
                    if (maxp[curr.second] >= 1 && p[curr.first] >= 1)
                        q.push(pii(curr.second + 1, curr.second + 2));
                }
            }
        }
    }

    cout << ans;
}
