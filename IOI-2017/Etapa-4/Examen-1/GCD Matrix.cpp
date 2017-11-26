#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef pair<int, int> pii;

int N, M, Q, x, y, r, c, ans;
int A[MAXN], B[MAXN], criba[MAXN];

vector<pii> canonica[MAXN];
long long CA[MAXN], CB[MAXN], H[MAXN], gcd[MAXN];

void divisores(int num, long long cont[], int n = 1, int i = 0) {
    if (i == canonica[num].size())
        cont[n]++;
    else for (int j = 0; j <= canonica[num][i].second; j++) {
        divisores(num, cont, n, i + 1);
        n *= canonica[num][i].first;
    }
}

void llenar(int v[], int ini, int fin, long long cont[]) {
    for (int i = ini; i <= fin; i++)
        divisores(v[i], cont);
}

int inclusion_exclusion(int n) {
    for (int i = 0; i < canonica[n].size(); i++)
        if (canonica[n][i].second > 1)
            return 0;
    return canonica[n].size() % 2 ? 1 : -1;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M >> Q;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 2; i < MAXN; i++) {
        if (!criba[i])
            for (int j = i; j < MAXN; j += i)
                criba[j] = i;

        for (int j = i; j > 1; ) {
            canonica[i].push_back(pii(criba[j], 0));
            for (int p = criba[j]; !(j % p); j /= p)
                canonica[i].back().second++;
        }
        H[i] = inclusion_exclusion(i);
    }

    while (Q--) {
        cin >> x >> y >> r >> c;
        memset(CA, 0, sizeof CA);
        memset(CB, 0, sizeof CB);
        memset(gcd, 0, sizeof gcd);

        ans = 0;
        llenar(A, x, r, CA);
        llenar(B, y, c, CB);

        for (int i = 1; i < MAXN; i++)
            if (CA[i] * CB[i]) {
                gcd[i] = CA[i] * CB[i];
                for (int j = 2 * i; j < MAXN; j += i)
                    gcd[i] -= H[j / i] * CA[j] * CB[j];
                ans += gcd[i] != 0;
            }

        cout << ans << "\n";
    }
}
