#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 10;

int n;
vector<int> dis(MAXN);

int main() {
    while (cin >> n && n) {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            qu.push(i);
        }

        dis.clear();
        for (int i = 1; i < n; i++) {
            dis.push_back(qu.front());
            qu.pop();
            qu.push(qu.front());
            qu.pop();
        }

        cout << "Discarded cards:";
        int sz = dis.size();
        for (int i = 0; i < sz; i++) {
            cout << ' ' << dis[i];
            if (i != sz - 1) {
                cout << ',';
            }
        }
        cout << '\n';
        cout << "Remaining card: " << qu.front() << '\n';
    }
}
