#include <bits/stdc++.h>
using namespace std;
main() {
   ios_base::sync_with_stdio(0); cin.tie();
   int N;
   cin >> N;

   int v[N], r[N];
   stack<int> p;
   for (int i = 0; i < N; i++) {
      cin >> v[i];
      r[i] = -1;
      while (!p.empty() && v[p.top()] < v[i]) {
         r[p.top()] = i + 1;
         p.pop();
      }
      p.push(i);
   }

   for (int i = 0; i < N; i++)
      cout << r[i] << " ";
}
