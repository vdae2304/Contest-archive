#include "cluedo.h"

// Main
// int Teoria(int c, int u, int a)

void ResolverCaso() {
    int c = 1, u = 1, a = 1, r;
    do {
        r = Teoria(c, u, a);
        switch (r) {
            case 1: c++; break;
            case 2: u++; break;
            case 3: a++;
        }
    }
    while (r != 0);
}
