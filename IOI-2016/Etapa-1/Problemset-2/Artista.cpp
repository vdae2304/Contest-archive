#include <bits/stdc++.h>
using namespace std;
main() {
   ios_base::sync_with_stdio(0); cin.tie();
   int M, N, G, C, K;
   cin >> M >> N >> G >> C >> K;

   stack<int> p[N][M];
   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
         for (int r = 0; r < G; r++)
            p[i][j].push(C);

   for (int r = 0; r < K; r++) {
      int Ci, Mi, Ni, Xi, Yi;
      cin >> Ci >> Mi >> Ni >> Xi >> Yi;

      for (int i = 0; i < Ni; i++)
         for (int j = 0; j < Mi; j++) {
            if (Ci != -1)
               p[Yi + i - 1][Xi + j - 1].push(Ci);
            else if (!p[Yi + i - 1][Xi + j - 1].empty())
               p[Yi + i - 1][Xi + j - 1].pop();
         }
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (p[i][j].empty())
            cout << "-1 ";
         else
            cout << p[i][j].top() << " ";
      }
      cout << endl;
   }
}
