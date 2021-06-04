#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int N;
    while (cin >> N) {
        int weight[1 << N];
        for (int i = 0; i < (1 << N); ++i)
            cin >> weight[i];

        //Calcula las potencias de cada vertice.
        int potency[1 << N];
        for (int i = 0; i < (1 << N); ++i) {
            potency[i] = 0;
            //Las esquinas adyacentes se obtienen invirtiendo algun bit.
            for (int j = 0; j < N; ++j)
                potency[i] += weight[i ^ (1 << j)];
        }

        //Calcula la maxima suma de potencias de dos vertices adyacentes.
        int ans = 0;
        for (int i = 0; i < (1 << N); ++i)
            for (int j = 0; j < N; ++j)
                ans = max(ans, potency[i] + potency[i ^ (1 << j)]);

        cout << ans << '\n';
    }
    return 0;
}
