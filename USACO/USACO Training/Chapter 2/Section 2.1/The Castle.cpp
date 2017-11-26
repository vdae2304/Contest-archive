/*
ID: vdae_231
PROG: castle
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int M, N;
int wall[50][50], room[50][50];
int roomsize[2500];
bool visited[50][50];

int floodfill(int nroom, int i, int j) {
    if (visited[i][j])
        return 0;

    int S = 1;
    visited[i][j] = true;
    room[i][j] = nroom;
    roomsize[nroom]++;

    if (!(wall[i][j] & 1))
        S += floodfill(nroom, i, j - 1);
    if (!(wall[i][j] & 2))
        S += floodfill(nroom, i - 1, j);
    if (!(wall[i][j] & 4))
        S += floodfill(nroom, i, j + 1);
    if (!(wall[i][j] & 8))
        S += floodfill(nroom, i + 1, j);

    return S;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("castle.in");
    ofstream cout("castle.out");
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> wall[i][j];

    int nrooms = 0, lroom = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!visited[i][j])
                lroom = max(lroom, floodfill(nrooms++, i, j));
    cout << nrooms << "\n" << lroom << "\n";

    int largest = 0, x, y; char c;
    for (int j = 0; j < M; j++)
        for (int i = N - 1; i >= 0; i--) {
            if (i > 0 && room[i][j] != room[i - 1][j]) {
                int t = roomsize[room[i][j]] + roomsize[room[i - 1][j]];
                if (t > largest) {
                    largest = t;
                    x = i + 1; y = j + 1;
                    c = 'N';
                }
            }
            if (j < M - 1 && room[i][j] != room[i][j + 1]) {
                int t = roomsize[room[i][j]] + roomsize[room[i][j + 1]];
                if (t > largest) {
                    largest = t;
                    x = i + 1; y = j + 1;
                    c = 'E';
                }
            }
        }
    cout << largest << "\n" << x << " " << y << " " << c << "\n";
}
