#include <iostream>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int M, N, K, l = 0;
    
    cin >> M >> N;
    int v[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];
    
    cin >> K;
    char mov[K];
    for (int i = 0; i < K; i++) {
        cin >> mov[l];
        if (l > 0 && mov[l] == mov[l - 1]) 
            l -= 2;
        else if (l > 4) 
            l -= 4;
        l++;
    }
    
    for (int r = 0; r < l; r++) {
        if (mov[r] == 'H') { 
            for (int j = 0; j < N / 2; j++)
                for (int i = 0; i < M; i++)
                    swap(v[i][j], v[i][N - j - 1]);
        }
        else if (mov[r] == 'V') { 
            for (int i = 0; i < M / 2; i++)
                for (int j = 0; j < N; j++)
                    swap(v[i][j], v[M - i - 1][j]);
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
