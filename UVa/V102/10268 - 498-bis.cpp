#include <bits/stdc++.h>
using namespace std;

long long x, tmp;
string input;
vector<long long> coef;

long long pow3(long long a,long long b)
{
    long long ans = 1, base = a;
    while (b != 0) {
        if(b & 1) {
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }
    return ans;
}

int main() {
    while (cin >> x) {
        cin.ignore(1);
        getline(cin, input);
        stringstream ss(input);

        coef.clear();
        while (ss >> tmp) {
            coef.push_back(tmp);
        }

        long long sum = 0;
        int n = coef.size() - 1;
        for (int i = 0; i < n; i++) {
            sum += coef[i] * (n - i) * pow3(x, n - i - 1);
        }
        cout << sum << '\n';
    }
}
