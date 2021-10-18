#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 10 + 5;

int n;
bool vis[MAXN];
priority_queue<int> qr;
priority_queue<int, vector<int>, greater<int>> ql;

int main() { IOS
    string s;
    cin >> n >> s;
    for (int i = 0; i < 10; i++) {
        qr.push(i);
        ql.push(i);
    }
    for (char c : s) {
        if (c == 'L') {
            int t = -1;
            while (!ql.empty()) {
                t = ql.top();
                ql.pop();
                if (!vis[t]) {
                    break;
                }
            }
            vis[t] = 1;
        } else if (c == 'R') {
            int t = -1;
            while (!qr.empty()) {
                t = qr.top();
                qr.pop();
                if (!vis[t]) {
                    break;
                }
            }
            vis[t] = 1;
        } else {
            int t = c - '0';
            vis[t] = 0;
            ql.push(t);
            qr.push(t);
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << vis[i];
    }
    cout << "\n";
}