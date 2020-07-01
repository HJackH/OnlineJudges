#include <bits/stdc++.h>
using namespace std;

const int MAXP = 2e7 + 5;

vector<int> primes;
vector<pair<int, int>> P;

void sieve() {
    vector<bool> notPrime(MAXP + 5, false);
    for (long long i = 2; i <= MAXP; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= MAXP; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int main() {
    sieve();
    for (int i = 1, ed = primes.size(); i < ed; i++) {
        if (primes[i] - primes[i - 1] == 2) {
            P.push_back(make_pair(primes[i - 1], primes[i]));
        }
    }

    int n;
    while (cin >> n) {
        cout << "(" << P[n - 1].first << ", " << P[n - 1].second << ")\n";
    }
}