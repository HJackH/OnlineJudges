#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1100;

bitset<MAXP + 5> isPrime;
string input;

void sieve() {
    isPrime.set();
    for (int i = 2; i <= MAXP; i++) {
        if (isPrime.test(i)) {
            for (int j = i * i; j <= MAXP; j += i) {
                isPrime.reset(j);
            }
        }
    }
}

int main() {
    sieve();
    while (cin >> input) {
        int sum = 0;
        for (char c : input) {
            if (isupper(c)) {
                sum += c - 'A' + 27;
            } else {
                sum += c - 'a' + 1;
            }
        }
        
        cout << "It is " << (isPrime.test(sum) ? "" : "not ") << "a prime word.\n";
    }
}