#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int N, root, father;
    cin >> N;

    vector<int> child[N + 1];
    for (int i = 0; i <= N; i++) {
        cin >> father;
        if (i == father)
            root = i;
        else
            child[father].push_back(i);
    }

    queue<int> c;
    c.push(root);

    while (!c.empty()) {
        int len = c.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < child[c.front()].size(); j++)
                c.push(child[c.front()][j]);
                
            if (c.front() == 0) {
                cout << len - 1;
                return 0;
            }
            
            c.pop();
        }
    }
}
