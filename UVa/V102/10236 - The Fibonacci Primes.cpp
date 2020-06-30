#include <bits/stdc++.h>
using namespace std;

const int MAXP = 250000;
const int MAXN = 22000 + 5;

bool notPrime[MAXP] = {0};
deque<int> primes;
vector<long double> fib;

void sieve() {
    for (long long i = 2; i < MAXP; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAXP; j += i) {
                notPrime[j] = true;
            }
        }
    }
    primes[0] = 3;
    primes[1] = 4;
}

void fibonacci() {
    long double n1 = 1, n2 = 1, n3;
    bool down = false;
    for (int i = 3, cnt = 0; i < MAXP && cnt < MAXN; i++) {
        n3 = n2 + (down ? n1 / 10 : n1);

        if (n3 > 1e9) {
            n3 /= 10;
            down = true;
        } else {
            down = false;
        }

        if (!primes.empty() && i == primes.front()) {
            primes.pop_front();
            fib.push_back(n3);
            cnt++;
        }
        n1 = n2;
        n2 = n3;
    }
}

int main() {
    sieve();
    fibonacci();

    int n;
    while (cin >> n) {
        cout << (long long)fib[n - 1] << '\n';
    }
}