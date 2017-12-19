#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
bool canBeReached[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, M, a, b;
    cin >> N >> M;

    canBeReached[0] = true;
    while (N--) {
        cin >> a >> b;
        if (canBeReached[a])
            for (int i = a; i <= b; i++)
                canBeReached[i] = true;
    }
    if (canBeReached[M])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
