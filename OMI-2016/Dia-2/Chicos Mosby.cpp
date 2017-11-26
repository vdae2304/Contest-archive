#include <iostream>
using namespace std;

int solve(int a, int b) {
   return b ? a / b + solve(b, a % b) : 0;
}

main() {
   int m, n;
   cin >> m >> n;
   cout << solve(max(m, n), min(m, n));
}
