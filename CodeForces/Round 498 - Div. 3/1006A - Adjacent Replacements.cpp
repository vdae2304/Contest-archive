#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n;
    cin >> n;
 
    long long v[n];
    for (long long i = 0; i < n; i++)
        cin >> v[i];
 
    for (long long a = 1, b = 1; b != INT_MAX; a = b) {
        for (long long i = 0; i < n; i++)
            if (v[i] == a) {
                if (a % 2)
                    v[i]++;
                else
                    v[i]--;
            }
        b = INT_MAX;
        for (long long i = 0; i < n; i++)
            if (v[i] > a)
                b = min(b, v[i]);
    }
 
    for (long long i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}