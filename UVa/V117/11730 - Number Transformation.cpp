#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

struct Node{
    int at;
    int depth;
};

int S, T, kase = 0, vis[MAXN + 5];
vector<int> primes, factors[MAXN + 5];

void run_prime() {
    vector<bool> notPrime(MAXN + 5, false);
    for (int i = 2; i <= MAXN; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= MAXN; j++) {
            notPrime[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

void run_factor() {
    for (int i = 4; i <= MAXN; i++) {
        int tmp = i, pnow = 0;
        while (tmp > 1 && primes[pnow] < i) {
            if (tmp % primes[pnow] == 0) {
                tmp /= primes[pnow];
                if (factors[i].empty() || primes[pnow] != factors[i].back())
                    factors[i].push_back(primes[pnow]);
            } else {
                pnow++;
            }
        }
    }
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push((Node) {S, 0});
    vis[S] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.at == T) {
            return now.depth;
        }
        for (int fac : factors[now.at]) {
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
    run_factor();
    while (cin >> S >> T && (S || T)) {
        cout << "Case " << ++kase << ": " << bfs() << '\n';
    }
}