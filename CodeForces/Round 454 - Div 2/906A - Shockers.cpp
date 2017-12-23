#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int n, ans = 0;
    bool isNot[26] = {}, notAsked[26] = {};
    cin >> n;

    while (--n) {
        char c;
        string s;
        cin >> c >> s;

        if (c == '.') {
            /*None of them are the selected letter*/
            for (int i = 0; i < s.size(); i++)
                isNot[s[i] - 'a'] = true;
        }
        else if (c == '!' || c == '?') {
            /*Counts the possible guessed letter:
            those who have been asked and haven't been discarded*/
            int cont = 0;
            for (int i = 0; i < 26; i++)
                if (!notAsked[i] && !isNot[i])
                    cont++;
            if (cont == 1)
                ans++;

            if (c == '!') {
                /*Mark the not asked letters*/
                char asked[26] = {};
                for (int i = 0; i < s.size(); i++)
                    asked[s[i] - 'a'] = true;
                for (int i = 0; i < 26; i++)
                    if (!asked[i])
                        notAsked[i] = true;
            }
            else if (c == '?')
                isNot[s[0] - 'a'] = true;
        }
    }

    cout << ans << "\n";
    return 0;
}
