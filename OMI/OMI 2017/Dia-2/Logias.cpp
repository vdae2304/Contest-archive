#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long N, M;
    cin >> N >> M;
    cout << (N % M) * ((N / M + 1) * (N / M)) / 2 + (M - (N % M)) * ((N / M) * (N / M - 1)) / 2
         << " " << ((N - M + 1) * (N - M)) / 2;
}
