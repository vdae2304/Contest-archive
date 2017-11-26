#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, D, ans = 0;
    cin >> N >> D;
  
    int desk[N];
    for (int i = 0; i < N; i++)
        cin >> desk[i];
 
    for (int i = 0; i < N - 1; ) {
        int last = min(i + D, N - 1);
        for (int j = i + 1; j <= i + D && j < N; j++)
            if (desk[j])
                last = j;
        ans += !desk[last];
        i = last;
    }
 
    cout << ans << "\n";
}
