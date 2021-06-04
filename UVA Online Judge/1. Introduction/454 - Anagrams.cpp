#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Regresa el arreglo de frecuencias de cada letra de un string dado.
vector<int> frequency(const string &s) {
    vector<int> f(256);
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != ' ')
            f[s[i]]++;
    return f;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;
    cin.ignore(2);

    while (T--) {
        //Lee todos los strings del caso y los ordena.
        string s;
        vector<string> arr;
        while (getline(cin, s) && s != "")
            arr.push_back(s);
        sort(arr.begin(), arr.end());

        //Prueba todos los pares viendo si son anagramas.
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                //Son anagramas si tienen el mismo arreglo de frecuencias.
                if (frequency(arr[i]) == frequency(arr[j]))
                    cout << arr[i] << " = " << arr[j] << '\n';
        if (T)
            cout << '\n';
    }
    return 0;
}
