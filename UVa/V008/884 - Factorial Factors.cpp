#include <bits/stdc++.h>
using namespace std;

const long long MAXP = 1e6;

int n, cnt[MAXP + 5];
vector<long long> primes;

void sieve() {
    memset(cnt, 0, sizeof (cnt));
    for (long long i = 2; i <= MAXP; i++) {
        if (!cnt[i]) {
            cnt[i] = 1;
            primes.push_back(i);
        }
        for (int j = 0, ed = primes.size(); j < ed && i * primes[j] <= MAXP; j++) {
            cnt[i * primes[j]] = cnt[i] + cnt[primes[j]];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    sieve();
    for (int i = 2; i <= MAXP; i++) {
        cnt[i] += cnt[i - 1];
    }

    while (cin >> n) {
        cout << cnt[n] << '\n';
    }
}