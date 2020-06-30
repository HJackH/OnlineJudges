#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 5;

struct Node {
    string at;
    int depth;
};

int n;
bool vis[MAXN];
string dic[MAXN], query;

bool comp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int bfs(string st, string ed) {
    queue<Node> q;
    q.push({st, 0});
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.at == ed) {
            return now.depth;
        }

        int nowlen = now.at.length();
        for (int i = 0; i < n; i++) {
            if (dic[i].length() < nowlen || vis[i]) {
                continue;
            }
            if (dic[i].length() > nowlen) {
                break;
            }
            
            int diff = 0;
            for (int j = 0; j < nowlen; j++) {
                if (now.at[j] != dic[i][j]) {
                    diff++;
                }
            }
            if (diff == 1) {
                q.push({dic[i], now.depth + 1});
                vis[i] = true;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--) {
        n = 0;
        while (getline(cin, dic[n]) && dic[n] != "*") {
            n++;
        }
        sort(dic, dic + n, comp);

        while (getline(cin, query) && query.length() > 0) {
            memset(vis, 0, sizeof(vis));
            stringstream ss(query);
            string st, ed;
            ss >> st >> ed;

            cout << st << " " << ed << " " << bfs(st, ed) << '\n';
        }
        if (T) {
            cout << '\n';
        }
    }
}