/*
ID: vdae_231
PROG: contact
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int A, B, N;
string s, aux;
map<string, int> DP;
vector<pair<int, string> > v;

bool comparar(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        if (a.second.size() == b.second.size())
            return a.second < b.second;
        return a.second.size() < b.second.size();
    }
    return a.first > b.first;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("contact.in");
    ofstream cout("contact.out");

    cin >> A >> B >> N;
    while (cin >> aux)
        s.append(aux);

    for (int i = 0; i <= s.size() - A; i++) {
        aux = s.substr(i, A - 1);
        for (int j = i + A - 1; j < i + B && j < s.size(); j++) {
            aux.push_back(s[j]);
            DP[aux]++;
        }
    }

    for (auto i = DP.begin(); i != DP.end(); i++)
        v.push_back(make_pair(i -> second, i -> first));
    sort(v.begin(), v.end(), comparar);

    for (int i = 0; i < v.size() && N--;) {
        int j = i;
        aux = "";
        cout << v[i].first << "\n";

        for (; i < v.size() && v[i].first == v[j].first; i++) {
            cout << aux << v[i].second;
            aux = ((i - j) % 6 == 5) ? "\n" : " ";
        }
        cout << "\n";
    }
}
