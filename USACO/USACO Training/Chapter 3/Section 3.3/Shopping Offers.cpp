/*
ID: vdae_231
PROG: shopping
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct offer {
    int N, P;
    pii product[5]; 
} v[100];

int S, B, price[1000];
map<vector<pii>, int> DP;

bool checkEmpty(vector<pii> &toBuy) {
    for (int i = 0; i < B; i++)
        if (toBuy[i].second)
            return false;
    return true;
}

bool checkOffer(vector<pii> &toBuy, int noOffer) {
    for (int i = 0, j = 0; i < v[noOffer].N; i++) {
        for (; j < B && toBuy[j].first < v[noOffer].product[i].first; j++);
        if (j == B || toBuy[j].first > v[noOffer].product[i].first || toBuy[j].second < v[noOffer].product[i].second)
            return false;
    }
    return true;
}

vector<pii> buyOffer(vector<pii> toBuy, int noOffer) {
    for (int i = 0, j = 0; i < v[noOffer].N; i++) {
        for (; j < B && toBuy[j].first < v[noOffer].product[i].first; j++);
        toBuy[j].second -= v[noOffer].product[i].second;
    }
    return toBuy;
}

vector<pii> buySolo(vector<pii> toBuy, int product) {
    toBuy[product].second--;
    return toBuy;
}

int Solve(vector<pii> toBuy) {
    if (checkEmpty(toBuy))
        return 0;
    else if (!DP[toBuy]) {
        int lowestPrice = INFINITY;

        for (int i = 0; i < S; i++)
            if (checkOffer(toBuy, i))
                lowestPrice = min(lowestPrice, Solve(buyOffer(toBuy, i)) + v[i].P);

        for (int i = 0; i < B; i++)
            if (toBuy[i].second)
                lowestPrice = min(lowestPrice, Solve(buySolo(toBuy, i)) + price[toBuy[i].first]);

        DP[toBuy] = lowestPrice;
    }
    return DP[toBuy];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("shopping.in");
    ofstream cout("shopping.out");

    cin >> S;
    for (int i = 0; i < S; i++) {
        cin >> v[i].N;
        for (int j = 0; j < v[i].N; j++)
            cin >> v[i].product[j].first >> v[i].product[j].second;
        sort(v[i].product, v[i].product + v[i].N);
        cin >> v[i].P;
    }

    cin >> B;
    vector<pii> toBuy;
    for (int i = 0, c, k, p; i < B; i++) {
        cin >> c >> k >> p;
        price[c] = p;
        toBuy.push_back(pii(c, k));
    }

    sort(toBuy.begin(), toBuy.end());
    cout << Solve(toBuy) << "\n";
}
