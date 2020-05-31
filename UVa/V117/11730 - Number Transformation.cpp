#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

struct Node{
    int at;
    int depth;
};

vector<int> prime;
set<int> Se[MAXN + 5];
int S, T, kase = 0;

void run_prime() {
    vector<bool> notPrime(MAXN + 5, false);
    for (int i = 2; i <= MAXN; i++) {
        if (!notPrime[i]) {
            prime.push_back(i);
        }
        for (int j : prime) {
            if (i * j > MAXN) {
                break;
            }
            notPrime[i * j] = true;
            if (i % j == 0) {
                break;
            }
        }
    }
}

void factor() {
    for (int i = 4; i <= MAXN; i++) {
        int tmp = i, fac = 0;
        while (tmp > 1 && prime[fac] < i) {
            if (tmp % prime[fac] == 0) {
                Se[i].insert(prime[fac]);
                tmp /= prime[fac];
            } else {
                fac++;
            }
        }
    }
}

int bfs() {
    vector<bool> vis(MAXN + 5, false);
    queue<Node> q;
    q.push((Node) {S, 0});
    vis[S] = true;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now.at == T) {
            return now.depth;
        }
        for (auto fac : Se[now.at]) {
            if (now.at + fac > T) {
                break;
            }
            if (!vis[now.at + fac]) {
                vis[now.at + fac] = true;
                q.push((Node) {now.at + fac, now.depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    run_prime();
    factor();
    while (cin >> S >> T && (S || T)) {
        cout << "Case " << ++kase << ": " << bfs() << '\n';
    }
}