#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    string s;
    cin >> N >> s;

    for (int i = 0, j; i < N; ) {
        if (s[i] == '?') {
            for (j = i; j < N && s[j] == '?'; j++);
            if (j - i > 1 || !i || j == N || s[i - 1] == s[j])
                ans = 1;
            i = j;
        }
        else {
            if (i && s[i - 1] == s[i]) {
                cout << "No\n";
                return 0;
            }
            i++;
        }
    }

    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
