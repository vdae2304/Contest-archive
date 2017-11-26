#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

bool fence[2001][2001];
void floodfill(int i, int j) {
    queue<point> c;
    c.push(point {i, j});

    while (!c.empty()) {
        point q = c.front();
        c.pop();

        if (q.x < 0 || q.x >= 2001 || q.y < 0 || q.y >= 2001 || fence[q.x][q.y])
            continue;
        fence[q.x][q.y] = true;

        c.push(point {q.x - 1, q.y});
        c.push(point {q.x, q.y - 1});
        c.push(point {q.x, q.y + 1});
        c.push(point {q.x + 1, q.y});
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("gates.in");
    ofstream cout("gates.out");
    int N, currX = 1000, currY = 1000;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int dirX = 0, dirY = 0; char c;
        cin >> c;
        switch (c) {
            case 'N': dirX -= 1; break;
            case 'W': dirY -= 1; break;
            case 'E': dirY += 1; break;
            case 'S': dirX += 1;
        }
        for (int j = 0; j < 2; j++) {
            currX += dirX;
            currY += dirY;
            fence[currX][currY] = true;
        }
    }

    int answer = -1;
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++)
            if (!fence[i][j]) {
                answer++;
                floodfill(i, j);
            }

    cout << answer;
}
