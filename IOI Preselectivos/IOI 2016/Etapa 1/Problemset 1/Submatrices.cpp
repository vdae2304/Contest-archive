#include <iostream>
using namespace std;

int M, N, R, C;
unsigned char A[1000][1000], B[1000][1000]; 
bool G[1000][1000];

void esSubmatriz(int a, int b) {
   for (int i = 0; i < R; i++) 
      for (int j = 0; j < C; j++) 
         if (A[i + a][j + b] != B[i][j])
            return;
   for (int i = 0; i < R; i++) 
      for (int j = 0; j < C; j++)
         G[i + a][j + b] = 1;
}

main() {
   ios_base::sync_with_stdio(0); cin.tie();
   cin >> M >> N;
   for (int i = 0; i < M; i++) 
      for (int j = 0; j < N; j++)
         cin >> A[i][j];
   
   cin >> R >> C;
   for (int i = 0; i < R; i++) 
      for (int j = 0; j < C; j++)
         cin >> B[i][j];
   
   for (int i = 0; i + R <= M; i++) 
      for (int j = 0; j + C <= N; j++)
         esSubmatriz(i, j);
   
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++)
         cout << G[i][j] << " ";
      cout << endl;
   }
}
