#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> B({0, 1}), R({1});

/*Prints polynom*/
void print(vector<int> &P) {
    cout << P.size() - 1 << "\n";
    for (int i = 0; i < P.size(); i++)
        cout << P[i] << " ";
    cout << "\n";
}

/*Returns C*x*P(x) + D*Q(x). Deg(P) > Deg(Q)*/
vector<int> product(int C, vector<int> &P, int D, vector<int> &Q) {
    vector<int> R;
    R.push_back(D*Q[0]);
    for (int i = 1; i < Q.size(); i++)
        R.push_back(C*P[i - 1] + D*Q[i]);
    for (int i = Q.size(); i <= P.size(); i++)
        R.push_back(C*P[i - 1]);
    return R;
}

/*Check it is a valid polynom*/
bool check(vector<int> &P) {
    for (int i = 1; i < P.size(); i++)
        if (abs(P[i]) > 1)
            return false;
    return P[P.size() - 1] == 1;
}

/*Perform Euclid's Algorithm in inverse order*/
void InverseGCD(int n, vector<int> &b, vector<int> &r) {
    if (!n) {
	print(b);
	print(r);
	exit(0);
    }
    else {
	vector<int> a1 = product(1, b, 1, r), a2 = product(1, b, -1, r);
	if (check(a1))
		InverseGCD(n - 1, a1, b);
	else
		InverseGCD(n - 1, a2, b);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> N;
    InverseGCD(N - 1, B, R);
    return 0;
}
