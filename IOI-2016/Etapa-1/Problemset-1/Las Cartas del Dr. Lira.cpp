#include <iostream>
using namespace std;
main() {
   int n, r = 0;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if ((i % 2 && c == 'W') || (!(i % 2) && c == 'B'))
         r++;
   }
   cout << min(r, n - r);
}
