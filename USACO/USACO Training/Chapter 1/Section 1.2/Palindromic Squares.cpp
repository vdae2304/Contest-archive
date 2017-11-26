/*
ID: vdae_231
PROG: palsquare
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int B;
string digit = "0123456789ABCDEFGHIJ";

string convert(int N) {
    string result;
    while (N) {
        result.push_back(digit[N % B]);
        N /= B;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isPalindrome(int N) {
    string p = convert(N);
    for (int i = 0; i < p.size() / 2; i++)
        if (p[i] != p[p.size() - i - 1])
            return false;
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("palsquare.in");
    ofstream cout("palsquare.out");

    cin >> B;
    for (int i = 1; i <= 300; i++)
        if (isPalindrome(i * i))
            cout << convert(i) << " " << convert(i * i) << "\n";
}
