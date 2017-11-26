/*
ID: vdae_231
PROG: heritage
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int izq[255], der[255], last = 1;
string in_order, pre_order, post_order;

void BuildTree(char node, int a, int b) {
    int m;
    for (m = a; m <= b && in_order[m] != node; m++);
    if (a <= m - 1) {
        izq[node] = pre_order[last++];
        BuildTree(izq[node], a, m - 1);
    }
    if (m + 1 <= b) {
        der[node] = pre_order[last++];
        BuildTree(der[node], m + 1, b);
    }
}

void doPost_Order(char node) {
    if (node) {
        doPost_Order(izq[node]);
        doPost_Order(der[node]);
        post_order.push_back(node);
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie();
    ifstream cin("heritage.in");
    ofstream cout("heritage.out");
    cin >> in_order >> pre_order;   
    BuildTree(pre_order[0], 0, in_order.size() - 1);
    doPost_Order(pre_order[0]);
    cout << post_order << "\n";
}
