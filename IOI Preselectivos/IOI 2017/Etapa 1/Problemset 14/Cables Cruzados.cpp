#include "CablesCruzados.h"
#include <bits/stdc++.h>
using namespace std;

// Main
//	bool RespuestaSublista(int desde, int hasta, int cruces)

int cuenta(int a, int b, int v[]) {
    if (a == b)
        return 0;
    else {
        int m = (a + b) / 2, ans = cuenta(a, m, v) + cuenta(m + 1, b, v);
        vector<int> izq, der;

        for (int i = a; i <= m; i++)
            izq.push_back(v[i]);
        sort(izq.begin(), izq.end());
        for (int i = m + 1; i <= b; i++)
            der.push_back(v[i]);
        sort(der.begin(), der.end());

        for (int i = 0, j = 0; i < izq.size(); i++, ans += j)
            for (; der[j] < izq[i] && j < der.size(); j++);

        RespuestaSublista(a, b, ans);
        return ans;
    }
}

void ContarCruces(int n, int Lista[]) {
	cuenta(0, n - 1, Lista);
}
