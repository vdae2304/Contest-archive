/*
ID: vdae_231
PROG: namenum
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("namenum.in");
    ifstream fin("dict.txt");
    ofstream cout("namenum.out");
    
    string num, name;
    cin >> num;

    int mapping[256], solutions = 0;
    mapping['A'] = mapping['B'] = mapping['C'] = '2';
    mapping['D'] = mapping['E'] = mapping['F'] = '3';
    mapping['G'] = mapping['H'] = mapping['I'] = '4';
    mapping['J'] = mapping['K'] = mapping['L'] = '5';
    mapping['M'] = mapping['N'] = mapping['O'] = '6';
    mapping['P'] = mapping['R'] = mapping['S'] = '7';
    mapping['T'] = mapping['U'] = mapping['V'] = '8';
    mapping['W'] = mapping['X'] = mapping['Y'] = '9';

    while (fin >> name)
        if (num.size() == name.size()) {
            bool valid = true;
            for (int i = 0; i < num.size(); i++)
                if (num[i] != mapping[name[i]])
                    valid = false;
            if (valid) {
                cout << name << "\n";
                solutions++;
            }
        }

    if (!solutions)
        cout << "NONE\n";
}
