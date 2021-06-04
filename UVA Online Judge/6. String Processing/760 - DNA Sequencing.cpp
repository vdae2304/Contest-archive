#include <iostream>
#include <cstring>
#include <set>
using namespace std;
#define maxn 301
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    string s1, s2;
    int dp[maxn][maxn]; //Mayor subcadena comun que termina en s1[i + 1] y s2[j + 1].
    bool end = false;
    
    while (cin >> s1 >> s2) {
        int maxlen = 0;
        memset(dp, 0, sizeof dp);

        //Procedemos por programacion dinamica.
        for (int i = 1; i <= s1.size(); ++i)
            for (int j = 1; j <= s2.size(); ++j) {
                //Los caracteres coinciden.
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                //Guardamos el mayor valor encontrado hasta ahora.
                maxlen = max(maxlen, dp[i][j]);
            }

        //Buscamos todas las subcadenas comunes con esa longitud.
        set<string> ans;
        for (int i = 1; i <= s1.size(); ++i)
            for (int j = 1; j <= s2.size(); ++j)
                if (dp[i][j] == maxlen) 
                    ans.insert(s1.substr(i - maxlen, maxlen));
        
        //Imprime la respuesta.
        if (end)
            cout << '\n';
        end = true;
        if (maxlen) {
            for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
                cout << *it << '\n';
        }
        else
            cout << "No common sequence.\n";
    }

    return 0;
}