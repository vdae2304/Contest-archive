#include <iostream>
using namespace std;

int matriz[1000][1000];

main() {
    int N, M, K;
    cin >> N >> M >> K;
    int mov[K], x = 500 - (M / 2), y = 500 - (N / 2);

    for (int i = 0; i < K; ++i)
        cin >> mov[i];
        
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j)
            cin >> matriz[i + y][j + x];

    for (int i = 0; i < K; ++i) {
        switch (mov[i]) {
            case 1:
                for (int i = 0; i < M; ++i)
                    matriz[y + N][i + x] = matriz[y][i + x];
                ++y;
                break;
            case 2:
                --y;
                for (int i = 0; i < M; ++i)
                    matriz[y][i + x] = matriz[y + N][i + x];
                break;
            case 3:
                for (int i = 0; i < N; ++i)
                    matriz[y + i][x + M] = matriz[y + i][x];
                ++x;
                break;
            case 4:
                --x;
                for (int i = 0; i < N; ++i)
                    matriz[y + i][x] = matriz[y + i][x + M];
                break;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << matriz[i + y][j + x] << " ";
        cout << endl;
    }
}
