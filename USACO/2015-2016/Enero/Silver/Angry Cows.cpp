#include <bits/stdc++.h>
using namespace std;

int N, K, cows[50000];

int calculate(int R) {
    int cont = 0, *index  = cows;
    while (index != cows + N) {
        cont++;
        index = upper_bound(index, cows + N, *index + 2 * R);
    }
    return cont;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> cows[i];
    sort(cows, cows + N);
   
    int low = 0, high = 500000000;
    while (low < high) {
        int mid = (low + high) / 2;
        if (calculate(mid) <= K)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low;
}
