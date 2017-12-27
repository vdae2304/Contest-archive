#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    string name, lastname;
    cin >> name >> lastname;

    cout << name[0];
    for (int i = 1; i < name.size() && name[i] < lastname[0]; i++)
        cout << name[i];
    cout << lastname[0];

    return 0;
}
