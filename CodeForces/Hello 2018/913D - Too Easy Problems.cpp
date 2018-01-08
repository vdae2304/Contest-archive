#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'000

int N, T;
int a[MAXN], t[MAXN];

bool sortT(int i, int j) {
    return t[i] < t[j];
}

vector<int> check(int A) {
    vector<int> P, Q;
    for (int i = 0; i < N; i++)
        if (a[i] >= A)
            P.push_back(i);
    sort(P.begin(), P.end(), sortT);

    for (int i = 0, Tt = T; i < P.size(); i++) {
        if (Tt - t[P[i]] >= 0)
            Q.push_back(P[i]);
        else
            break;
        Tt -= t[P[i]];
    }
    return Q;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N >> T;

    for (int i = 0; i < N; i++)
        cin >> a[i] >> t[i];

    int low = 0, high = N + 1;
    vector<int> v;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        v = check(mid);
        if (v.size() >= mid)
            low = mid;
        else
            high = mid - 1;
    }

    v = check(low);
    cout << low << "\n" << low << "\n";
    for (int i = 0; i < low && i < v.size(); i++)
        cout << v[i] + 1 << " ";
    return 0;
}
