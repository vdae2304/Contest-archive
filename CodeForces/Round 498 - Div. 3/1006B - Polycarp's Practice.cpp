#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pii;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n, k;
    cin >> n >> k;
 
    long long v[n], s = 0;
    pii w[n];
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = pii(-v[i], i);
    }
    sort(w, w + n);
 
    for (long long i = 0; i < k; i++) {
        v[w[i].second] = INT_MAX;
        s -= w[i].first;
    }
 
    cout << s << "\n";
    for (long long i = -1, j, k; i < n; i = j) {
        for (j = i + 1; j < n && v[j] != INT_MAX; j++);
        for (k = j + 1; k < n && v[k] != INT_MAX; k++);
        if (k < n)
            cout << j - i << " ";
        else {
            cout << n - 1 - i << " ";
            break;
        }
    }
    return 0;
}