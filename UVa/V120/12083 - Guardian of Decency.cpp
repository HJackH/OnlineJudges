#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;

struct Student {
    int h;
    char gender;
    string music;
    string sport;
};

int n;
Student a[MAXN];
vector<int> G[MAXN];
int vy[MAXN], my[MAXN];

bool match(int u) {
    for (int v : G[u]) {
        if (vy[v]) {
            continue;
        }
        vy[v] = true;
        if (my[v] == -1 || match(my[v])) {
            my[v] = u;
            return true;
        }
    }
    return false;
}

int sol() {
    int cnt = 0;
    memset(my, -1, sizeof(my));
    for (int i = 0; i < n; i++) {
        memset(vy, 0, sizeof(vy));
        if (match(i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].h >> a[i].gender >> a[i].music >> a[i].sport;
            G[i].clear();
        }

        for (int i = 0; i < n; i++) {
            if (a[i].gender == 'M') {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (abs(a[i].h - a[j].h) > 40 || a[i].gender == a[j].gender || a[i].music != a[j].music || a[i].sport == a[j].sport) {
                    continue;
                }
                G[i].push_back(j);
            }
        }

        cout << n - sol() << "\n";
    }
}