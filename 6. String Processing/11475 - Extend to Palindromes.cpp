#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100001

string text, pattern;
int lps[maxn];

//Algoritmo de KMP.
void kmp_preprocess() {
    lps[0] = 0;
    for (int i = 1; i < pattern.size(); ++i) {
        int j = lps[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = lps[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        lps[i] = j;
    }
}

//Buscamos el mayor prefijo de pattern que sea sufijo de text.
int kmp_search() {
    for (int i = 0, j = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = lps[j - 1];
        if (text[i] == pattern[j])
            ++j;
        //Regresamos el mayor prefijo de pattern que matcheo al final de text.
        if (i == text.size() - 1) 
            return j;
        if (j == pattern.size())
            j = lps[j - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    while (cin >> text) {
        //Definimos pattern como el reverso de text.
        pattern = text;
        reverse(pattern.begin(), pattern.end());
        //Observemos que text + pattern es palindromo (por como escogimos pattern).
        //Sin embargo, los caracteres que podamos matchear, los traslapamos.
        kmp_preprocess();
        for (int i = kmp_search(); i < pattern.size(); ++i)
            text.push_back(pattern[i]);
        cout << text << '\n';
    }
    return 0;
}