#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 100;

vector<int> p;

// primes
void run_prime() {
    vector<bool> notP(MAXN, 0);
    for (int i = 2; i <= MAXN; i++) {
        if (!notP[i]) {
            p.pb(i);
        }
        for (auto j : p) {
            if (i * j > MAXN) {
                break;
            }
            notP[i * j] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}

int main() { IOS
    run_prime();

    // n = number of primes <= 100
    int n = p.size();

    vector<vector<int>> ans(MAXN + 5, vector<int> (n, 0));
    for (int i = 2; i <= MAXN; i++) {
        int tmp = i;
        for (int j = 0; j < n; j++) {
            while (tmp % p[j] == 0) {
                ++ans[i][j];
                tmp /= p[j];
            }
            // prefix sum
            ans[i][j] += ans[i - 1][j];
        }
    }

    int x;
    while (cin >> x && x) {
        cout.width(3);
        cout << x << "! =";
        for (int i = 0; i < n && ans[x][i]; i++) {
            if (i == 15) {
                cout << "\n      ";
            }
            cout.width(3);
            cout << ans[x][i];
        }
        cout << '\n';
    }
}