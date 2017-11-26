#include <iostream>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, x, smallestOdd = 1 << 30;
    unsigned long long S = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        S += x;
        if (x < smallestOdd && x % 2)
            smallestOdd = x;
    }
    if (S % 2)
        cout << S;
    else if (smallestOdd != 1 << 30)
        cout << S - smallestOdd;
    else
        cout << "0";
}
