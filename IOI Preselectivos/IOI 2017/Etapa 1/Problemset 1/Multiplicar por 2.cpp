#include <iostream>
using namespace std;
main() {
    int a, b;
    cin >> a >> b;
    while (!(a % 2))
        a /= 2;
    while (!(b % 2))
        b /= 2;
    if (a == b)
        cout << "felizmil";
    else
        cout << "tristemil";
}
