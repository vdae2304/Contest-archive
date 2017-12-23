#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    char board[9][9];
    int x, y;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    cin >> x >> y;
    x = (x - 1) % 3;
    y = (y - 1) % 3;

    /*Fill the correct area*/
    bool noEmpty = true;
    for (int i = 3*x; i < 3*x + 3; i++)
        for (int j = 3*y; j < 3*y + 3; j++)
            if (board[i][j] == '.') {
                board[i][j] = '!';
                noEmpty = false;
            }

    /*If it's already full, fill all the board*/
    if (noEmpty)
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    board[i][j] = '!';

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
            if (j % 3 == 2)
                cout << " ";
        }
        cout << "\n";
        if (i % 3 == 2)
            cout << "\n";
    }
    return 0;
}
