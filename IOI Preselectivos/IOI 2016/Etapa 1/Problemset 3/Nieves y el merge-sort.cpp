#include <iostream>
using namespace std;

int N, v[65536];

void merge_sort(int *v, int N) {
    if (N > 1) {
        int m = N / 2, izq[m], der[N - m];
        
        for (int i = 0; i < m; i++)
            izq[i] = v[i];
        for (int i = m; i < N; i++)
            der[i - m] = v[i];
            
        merge_sort(izq, m);
        merge_sort(der, N - m);
        
        int i = 0, j = N - m - 1, k = 0;
        while (i < m && j >= 0)
            v[k++] = izq[i] <= der[j] ? izq[i++] : der[j--];
        while (i < m)
            v[k++] = izq[i++];
        while (j >= 0)
            v[k++] = der[j--];
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> v[i];
        
    merge_sort(v, N);
    for (int i = 0; i < N; i++)
        cout << v[i] << " ";
}
