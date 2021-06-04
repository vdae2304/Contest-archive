#include <iostream>
#include <sstream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int best = -1;
    string text, word, ans;

    //Leemos el diccionario de palabras.
    set<string> dict;
    while (cin >> word, word != "#")
        dict.insert(word);
    cin.ignore();

    //Probamos todos los posibles valores de K.
    getline(cin, text);
    for (int K = 0; K < 27; ++K) {
        //Deciframos el texto.
        string deciph = text;
        for (int i = 0; i < text.size(); ++i) {
            int c = (text[i] != ' ') ? text[i] - 'A' + 1 : 0;
            c = (c + K) % 27;
            deciph[i] = c ? c + 'A' - 1 : ' ';
        }
        //Guardamos el numero de palabras en el diccionario.
        int indict = 0;
        stringstream in = stringstream(deciph);
        while (in >> word)
            indict += dict.count(word);
        //Actualizamos.
        if (indict > best) {
            best = indict;
            ans = deciph;
        }
    }
    
    //Imprime la respuesta.
    int cont = 0;
    stringstream in = stringstream(ans);
    while (in >> word) {
        if (cont + (cont > 0) + word.size() > 60) {
            cout << '\n';
            cont = 0;
        }
        if (cont) {
            cout << ' ';
            cont++;
        }
        cout << word;
        cont += word.size();
    }
    cout << '\n';

    return 0;
}