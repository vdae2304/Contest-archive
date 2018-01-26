#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'000
#define MAXP 1'000'000
#define MAXE 1'000'000'000
typedef pair<int, int> pii;

int N, M;
long long sp, mst;
bool Criba[MAXP];
vector<pii> graph[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    for (long long i = 2; i * i <  MAXP; i++)
        if (!Criba[i]) {
            for (long long j = i * i; j < MAXP; j += i)
                Criba[j] = true;
        }

    cin >> N >> M;
    for (int i = N; i > 2; i--) {
        graph[1].push_back(pii(i, 2));
        mst += 2;
        M--;
    }

    for (int i = 2; ; i++)
        if (!Criba[mst + i]) {
            graph[1].push_back(pii(2, i));
            mst += i;
            sp = 2;
            M--;
            break;
        }

    for (int i = 2; M > 0; i++)
        for (int j = i + 1; j <= N && M--; j++)
            graph[i].push_back(pii(j, MAXE));

    cout << sp << " " << mst << "\n";
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < graph[i].size(); j++)
            cout << i << " " << graph[i][j].first << " " << graph[i][j].second << "\n";
    return 0;
}
