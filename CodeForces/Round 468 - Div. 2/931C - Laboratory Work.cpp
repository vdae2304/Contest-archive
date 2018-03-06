#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, S, x;
vector<pii> X;
vector<int> Y;

void Insert() {
    for (int i = 0; i < X.size(); i++)
        if (x == X[i].first) {
            X[i].second++;
            return;
        }
    X.push_back(pii(x, 1));
}

void AddToAnswer(int i, int t) {
    N -= t;
    Y.insert(Y.end(), t, X[i].first);
    M += min(X[i].second, t);
    X[i].second -= min(X[i].second, t);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        Insert();
    }

    /**If X is not contiguous, fill it**/
    if (X.size() == 2 && abs(X[0].first - X[1].first) > 1)
            X.push_back(pii((X[0].first + X[1].first) / 2, 0));
    sort(X.begin(), X.end());

    if (X.size() < 3) { /**No changes can be done**/
        for (int i = 0; i < X.size(); i++)
            AddToAnswer(i, X[i].second);
    }
    else { /**Biject the solution to the set {-1,0,1}**/
        for (int i = 0; i < 3; i++)
            S += (X[i].first - X[1].first) * X[i].second;

        if (S > 0)
            AddToAnswer(2, S);
        else if (S < 0)
            AddToAnswer(0, -S);
        AddToAnswer(1, N % 2);

        if (min(N/ 2, X[0].second) + min(N / 2, X[2].second) < min(N, X[1].second)) {
            AddToAnswer(0, N / 2);
            AddToAnswer(2, N);
        }
        else
            AddToAnswer(1, N);
    }

    /**Print answer**/
    cout << M << "\n";
    for (int i = 0; i < Y.size(); i++)
        cout << Y[i] << " ";

    return 0;
}
