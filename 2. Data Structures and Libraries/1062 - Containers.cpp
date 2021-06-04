#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    string s;
    cin >> s;

    for (int ncase = 1; s != "end"; ++ncase) {
        set<char> stacks; //Elementos en la cima de cada contenedor.

        for (int i = 0; i < s.size(); ++i) {
            //Busca el contenedor con menor caracter en la cima y que sea mayor o igual al caracter actual.
            set<char>::iterator it = stacks.lower_bound(s[i]);
            //Si encontro un contenedor, lo actualiza. De lo contrario, crea uno nuevo.
            if (it != stacks.end())
                stacks.erase(it);
            stacks.insert(s[i]);
        }

        cout << "Case " << ncase << ": " << stacks.size() << '\n';
        cin >> s;
    }
    return 0;
}
