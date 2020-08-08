#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXT = 1000 + 5;

int t, n, num;
bool inq[MAXT];
unordered_map<int, int> M;
deque<int> qt, q[MAXT];

int main() {
    IOS
    int kase = 0;
    while (cin >> t && t) {
        M.clear();
        for (int i = 0; i < t; i++) {
            inq[i] = false;
            q[i].clear();
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> num;
                M[num] = i;
            }
        }

        qt.clear();
        int team;
        string cmd;
        cout << "Scenario #" << ++kase << '\n';
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                cin >> num;
                team = M[num];
                if (!inq[team]) {
                    qt.push_back(team);
                    inq[team] = true;
                }
                q[team].push_back(num);
            } else {
                team = qt.front();
                cout << q[team].front() << '\n';
                q[team].pop_front();
                if (q[team].empty()) {
                    qt.pop_front();
                    inq[team] = false;
                }
            }
        }
        cout << '\n';
    }
}