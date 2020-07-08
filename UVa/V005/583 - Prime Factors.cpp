#include <bits/stdc++.h>
using namespace std;

const long long MAXP = sqrt(1LL << 31);

long long n;
vector<long long> primes;

void sieve() {
    bitset<MAXP + 5> notPrime;
    notPrime.reset();
    for (long long i = 2; i <= MAXP; i++) {
        if (!notPrime.test(i)) {
            primes.push_back(i);
        }
        for (int j = 0, ed = primes.size(); j < ed && i * primes[j] <= MAXP; j++) {
            notPrime.set(i * primes[j]);
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    sieve();
    while (cin >> n && n) {
        cout << n << " = ";

        bool first = true;
        if (n < 0) {
            n = -n;
            cout << "-1";
            first = false;
        }

        for (long long i : primes) {
            while (n % i == 0) {
                n /= i;
                if (!first) {
                    cout << " x ";
                }
                first = false;
                cout << i;
            }
            if (n <= 1) {
                break;
            }
        }

        if (n > 1) {
            if (!first) {
                cout << " x ";
            }
            cout << n;
        }
        cout << '\n';
    }
}