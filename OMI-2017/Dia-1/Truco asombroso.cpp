#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, ans = 0;
    string s;
    cin >> N >> s;

    for (int i = N - 1, j; i > 0; ) {
        if (s[i] == '0') {
            ans++;
            i--;
        }
        else {
            for (j = i; j >= 0 && s[j] == '1'; j--);
            if (i - j == 1 || (i - j == 2 && j < 0))
                ans += 2;
            else {
                ans += i - j + 1;
                s[max(j, 0)] = '1';
            }
            i = j;
        }
    }

    cout << ans;
}
