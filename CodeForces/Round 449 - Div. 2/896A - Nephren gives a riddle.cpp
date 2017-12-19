#include <bits/stdc++.h>
using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?",
       fn0 = "What are you doing while sending \"", fn1 = "\"? Are you busy? Will you send \"", fn2 = "\"?";
vector<long long> Length;

long long getLength(int n) {
    return n < Length.size() ? Length[n] : 1e18;
}

char Solve(long long k, int n) {
    if (!n)
        return k < f0.size() ? f0[k] : '.';
    else {
        if (k < fn0.size())
            return fn0[k];
        k -= fn0.size();

        if (k < getLength(n - 1))
            return Solve(k, n - 1);
        k -= getLength(n - 1);

        if (k < fn1.size())
            return fn1[k];
        k -= fn1.size();

        if (k < getLength(n - 1))
            return Solve(k, n - 1);
        k -= getLength(n - 1);

        if (k < fn2.size())
            return fn2[k];
        return '.';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    long long q, n, k;
    string s;
    cin >> q;

    Length.push_back(f0.size());
    for (int i = 1; Length.back() < 1e18; i++)
        Length.push_back(fn0.size() + fn1.size() + fn2.size() + 2*Length.back());

    while (q--) {
        cin >> n >> k;
        s.push_back(Solve(k - 1, n));
    }
    cout << s << "\n";
    return 0;
}
