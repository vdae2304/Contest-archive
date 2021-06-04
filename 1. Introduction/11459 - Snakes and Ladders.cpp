#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;

        //Para cada casilla, guarda el otro extremo de la serpiente o escalera.
        int board[101];
        for (int i = 1; i <= 100; ++i)
            board[i] = i;
        while (B--) {
            int b1, b2;
            cin >> b1 >> b2;
            board[b1] = b2;
        }

        //Posiciones de los jugadores y jugador en turno (0 si el juego ya termino).
        int pos[A + 1], turn = 1;
        for (int i = 1; i <= A; ++i)
            pos[i] = 1;

        //Simula el juego.
        while (C--) {
            int dice;
            cin >> dice;
            if (turn != 0) {
                pos[turn] = board[min(100, pos[turn] + dice)];
                if (pos[turn] == 100)
                    turn = 0;
                else
                    turn = (turn % A) + 1;
            }
        }

        //Imprime la respuesta.
        for (int i = 1; i <= A; ++i)
            cout << "Position of player " << i << " is " << pos[i] << ".\n";
    }
    return 0;
}
