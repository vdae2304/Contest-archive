#include "ferrocarril.h"
#include <algorithm>
using namespace std;

// Main
//	int EncontrarVagon(int v)
//	int VagonEnPosicion(int p)
//	int IntercambiarVagones(int a, int b)

void AcomodarFerrocarril(int n) {
    //Llevamos el vag�n i a su lugar
    for (int i = 1; i < n; i++) {
        //Se encuentra en su lugar
        if (VagonEnPosicion(i) == i)
            continue;

        int j = EncontrarVagon(i), l = j - i;

        //Puede acomodarse en un solo movimiento
        if (i + 2 * l - 1 <= n)
            IntercambiarVagones(i, i + 2 * l - 1);
        //Acercamos el vag�n y despu�s lo llevamos a su lugar (2 movimientos)
        else {
            //El segmento [i..j] es par
            if (l % 2)
                IntercambiarVagones(i, j);
            //Consideramos el segmento [i + 1..j]
            else
                IntercambiarVagones(i + 1, j);
            j = (i + j) / 2, l = j - i;
            IntercambiarVagones(i, i + 2 * l - 1);
        }
    }
}
