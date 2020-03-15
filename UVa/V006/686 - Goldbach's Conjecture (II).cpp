#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 << 15;

vector<int> lp(MAXN + 50, 0);
vector<int> prime;
int n, sz;

void run() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back(i);
        }

        for (int j = 0; (j < prime.size()) && (prime[j] <= lp[i]) && (i * prime[j] <= MAXN); j++) {
            lp[i * prime[j]] = prime[j];
        }
    }
    sz = prime.size();
}

int BSearch(int x) {
    int left = 0, right = sz - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (prime[mid] <= x && x < prime[mid + 1]) {
            return mid;
        } else if (x < prime[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    run();

    while (cin >> n && n) {
        
        int L = 0, R = BSearch(n), cnt = 0;
        while (L <= R && prime[L] <= (n + 1) / 2) {
            if (prime[L] + prime[R] > n) {
                R--;
            } else if (prime[L] + prime[R] < n) {
                L++;
            } else {
                cnt++;
                L++;
                R--;
            }
        }
        cout << cnt << endl;
    }
}