#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N;
    string leds[10];
    string digits[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY",
                         "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};

    while (cin >> N, N != 0) {
        for (int i = 0; i < N; ++i)
            cin >> leds[i];

        //Supone que la cuenta regresiva empieza en t.
        bool valid = false;
        for (int t = N - 1; t < 10; ++t) {
            //Verifica si la cuenta regresiva pudo haber empezado en t.
            bool ok = true;
            bool burned[7] = {};

            for (int i = 0; i < N; ++i) 
                for (int j = 0; j < 7; ++j) {
                    //Si el led esta encendido cuando deberia estar fundido o apagado, 
                    //significa que no es una cuenta regresiva valida.
                    if (leds[i][j] == 'Y' && (burned[j] || digits[t - i][j] == 'N'))
                        ok = false;
                    //Si el led esta apagado cuando deberia estar encendido, significa
                    //que se fundio.
                    if (leds[i][j] == 'N' && digits[t - i][j] == 'Y')
                        burned[j] = true;
                }

            //Encontramos una cuenta regresiva valida.
            if (ok) {
                valid = true;
                break;            
            }
        }

        //Imprime la respuesta.
        if (valid)
            cout << "MATCH\n";
        else
            cout << "MISMATCH\n";
    }

    return 0;
}