#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int n;
    cin >> n;
    if (n % 10 <= 5)
        cout << n - (n % 10);
    else
        cout << n + (10 - n % 10);
    return 0;
}
