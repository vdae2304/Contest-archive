#include <bits/stdc++.h>
using namespace std;

int indice(string N, string x) {
    int ans = 0;
    string M (N.size(), '0');

    for (int i = 0; i < x.size(); i++) {
        ans++;
        for (char j = '0' + !i; j < x[i]; j++) {
            int p = 1;
            for (int k = i; k < N.size() - 1; k++)
                ans += p, p *= 10;

            M[i] = j;
            if (strncmp(M.c_str(), N.c_str(), i + 1) < 0)
                ans += p;
            else if (!strncmp(M.c_str(), N.c_str(), i + 1))
                ans += max(atoi(N.c_str()) - atoi(M.c_str()) + 1, 0);
        }
        M[i] = x[i];
    }

    return ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string N, x;
    int Q;
    cin >> N >> Q;
    while (Q--) {
        cin >> x;
        cout << indice(N, x) << "\n";
    }
}
