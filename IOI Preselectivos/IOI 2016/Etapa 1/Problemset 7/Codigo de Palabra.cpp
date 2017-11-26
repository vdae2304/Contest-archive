#include <bits/stdc++.h>
using namespace std;

int cuenta(char c, int M) {
    if (M <= 0)
        return 1;
    else if (M == 1)
        return 'z' - c + 1;
    else {
        int cont = 0;
        for (char i = c; i <= 'z'; i++)
            cont += cuenta(i + 1, M - 1);
        return cont;
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string s;
    cin >> s;

    int T = 0;
    for (int i = 0; i < s.size(); i++)
        T += cuenta('a', i);

    for (int i = 0; i < s.size(); i++) {
        if (i && s[i - 1] >= s[i]) {
            cout << "0";
            return 0;
        }
        
        char c = i ? s[i - 1] + 1 : 'a';
        for (char j = c; j < s[i]; j++)
            T += cuenta(j + 1, s.size() - i - 1);
    }

    cout << T;
}
