#include <bits/stdc++.h>
using namespace std;

struct node {
    node *nxt[10];

    node() {
        memset(nxt, 0, sizeof nxt);
    }
};

void Insert(node *p, string &s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        if (!p->nxt[s[i] - '0'])
            p->nxt[s[i] - '0'] = new node();
        p = p->nxt[s[i] - '0'];
    }
}

vector<string> v;
void DFS(node *p, string s) {
    bool isEnd = true;
    for (int i = 0; i < 10; i++)
        if (p->nxt[i]) {
            isEnd = false;
            DFS(p->nxt[i], s + char('0' + i));
        }
    reverse(s.begin(), s.end());
    if (isEnd)
        v.push_back(s);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    int n, m;
    string name, phone;
    map<string, node*> book;
    cin >> n;

    while (n--) {
        cin >> name >> m;
        if (!book[name])
            book[name] = new node();
        while (m--) {
            cin >> phone;
            Insert(book[name], phone);
        }
    }

    cout << book.size() << "\n";
    for (auto p : book) {
        v.clear();
        DFS(p.second, "");
        cout << p.first << " " << v.size() << " ";
        for (string s : v)
            cout << s << " ";
        cout << "\n";
    }
    return 0;
}
