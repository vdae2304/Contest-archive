#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010

int N, M, s[MAXN], x;
long long ans;
int cont[MAXN], smaller[MAXN], pre[MAXN], nxt[MAXN];

void Build() {
    for (int i = 1, aux = -1e7; i < MAXN; i++) {
        smaller[i] = smaller[i - 1] + cont[i];
        if (cont[i]) aux = i;
        pre[i] = aux;
    }
    for (int i = MAXN - 1, aux = 1e7; i >= 0; i--) {
        if (cont[i]) aux = i;
        nxt[i] = aux;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < M; i++) {
        cin >> x;
        cont[x]++;
    }
    Build();

    for (int i = 0, j; i < N; i++)
        if (!s[i]) {
            for (j = i; j < N && !s[j]; j++);
            int a = i ? s[i - 1] : s[j], b = j < N ? s[j] : s[i - 1];
            if (a > b) swap(a, b);

            if (!i && j >= N)
                fill(s, s + N, x);
            else if (smaller[b] - smaller[a - 1])
                fill(s + i, s + j, nxt[a]);
            else
                fill(s + i, s + j, a - pre[a] < nxt[b] - b ? pre[a] : nxt[b]);
        }

    for (int i = 1; i < N; i++)
        ans += abs(s[i] - s[i - 1]);

    cout << ans << "\n";
    for (int i = 0; i < N; i++)
        cout << s[i] << " ";
}
