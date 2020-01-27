#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long n;
    cin >> n;
 
    long long v[n], ans = 0;
    for (long long i = 0; i < n; i++)
        cin >> v[i];
 
    long long s1 = 0, s3 = 0, i = -1, j = n;
    while (i < j) {
        if (s1 < s3)
            s1 += v[++i];
        else if (s1 > s3)
            s3 += v[--j];
        else {
            ans = max(ans, s1);
            s1 += v[++i];
            s3 += v[--j];
        }
    }
 
    cout << ans;
    return 0;
}