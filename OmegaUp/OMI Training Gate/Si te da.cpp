#include <bits/stdc++.h>
using namespace std;
main() {
   int a, b, cont = 0;
   cin >> a >> b;
   
   int c = a, d = b;
   do {
      cout << c << " ";
      c = (c + d) % 10;
      swap(c, d);
      cont++;
   }
   while (!(a == c && b == d));
   
   cout << c << " " << d << "\n" << cont;
}
