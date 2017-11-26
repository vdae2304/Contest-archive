#include <iostream>
using namespace std;
main() {
    int N, K, mayor = -10000;
    cin >> N >> K;
    
    int visitas[N];
    for (int i = 0; i < N; ++i)
        cin >> visitas[i];
        
    for (int i = 0; i <= N - K; ++i) 
        mayor = max(mayor, visitas[i + K - 1] - visitas[i]);
    cout << mayor;
}
