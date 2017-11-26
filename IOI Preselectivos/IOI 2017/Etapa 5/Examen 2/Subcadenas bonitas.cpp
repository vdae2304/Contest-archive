#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

string s, aux = "AEIOUaeiou";
int DP[MAXN], ST[4 * MAXN], max_len, cont;

void Build(int i, int j, int n) {
    if (i == j)
        ST[n] = DP[i];
    else {
        Build(i, (i + j) / 2, 2 * n + 1);
        Build((i + j) / 2 + 1, j, 2 * n + 2);
        ST[n] = max(ST[2 * n + 1], ST[2 * n + 2]);
    }
}

int Query(int l, int i, int j, int n) {
    if (j < l || ST[n] < DP[l])
        return -1;
    if (i == j)
        return i;
    int der = Query(l, (i + j) / 2 + 1, j, 2 * n + 2);
    return der != -1 ? der : Query(l, i, (i + j) / 2, 2 * n + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> s;

    for (int i = 1; i <= s.size(); i++) {
        bool is_vowel = binary_search(aux.begin(), aux.end(), s[i - 1]);
        DP[i] = DP[i - 1] + (is_vowel ? -1 : 2);
    }
    Build(0, s.size(), 0);

    for (int i = 0; i <= s.size(); i++)
        max_len = max(max_len, Query(i, 0, s.size(), 0) - i);
    for (int i = max_len; i <= s.size(); i++)
        cont += DP[i - max_len] <= DP[i];

    if (max_len)
        cout << max_len << " " << cont;
    else
        cout << "Sin solucion";
}
