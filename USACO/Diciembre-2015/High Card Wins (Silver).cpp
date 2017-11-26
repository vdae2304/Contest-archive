#include <bits/stdc++.h>
using namespace std;

int N, puntos;
int Bessie[50001], Elsie[50001];
bool ElsiePosee[100001];

main() {
   ios_base::sync_with_stdio(0); cin.tie();
   ifstream cin("highcard.in");
   ofstream cout("highcard.out");
   cin >> N;

   for (int i = 0, aux; i < N; i++) {
      cin >> aux;
      ElsiePosee[aux] = true;
   }

   int Bi = 0, Ei = 0;
   for (int i = 1; i <= 2 * N; i++) {
      if (ElsiePosee[i])
         Elsie[Ei++] = i;
      else
         Bessie[Bi++] = i;
   }

   Bi = Ei = 0;
   while (Bi < N && Ei < N) {
      if (Elsie[Ei] < Bessie[Bi]) {
         puntos++;
         Ei++;
      }
      Bi++;
   }
   cout << puntos;
}
