#include <bits/stdc++.h>
using namespace std;

int p, c;

int main() {
    int kase = 0;
    while (cin >> p >> c && (p || c)) {
        list<int> a;
        for (int i = 1, ed = min(p, c); i <= ed; i++) {
            a.push_back(i);
        }

        cout << "Case " << ++kase << ":\n";

        char cmd;
        int x;
        while (c--) {
            cin >> cmd;
            if (cmd == 'N') {
                x = a.front();
                cout << x << "\n";
                a.push_back(x);
                a.pop_front();
            } else {
                cin >> x;
                a.remove(x);
                a.push_front(x);
            }
        }
    }
}