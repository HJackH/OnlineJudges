#include <bits/stdc++.h>
using namespace std;

#define LL long long

int kase = 0;
long long n, BanNum[] = {(LL)1e7, (LL)1e5, (LL)1e3, (LL)1e2};
int sz = sizeof(BanNum) / sizeof(BanNum[0]);
string BanName[] = {"kuti", "lakh", "hajar", "shata"};

void calc(long long x) {
    for (int i = 0; i < sz; i++) {
        long long quo = x / BanNum[i];
        if (quo > 0) {
            cout << ' ' << quo << ' ' << BanName[i];
            x %= BanNum[i];
        }
    }
    if (x > 0) {
        cout << ' ' << x;
    }
}

int main() {
    while (cin >> n) {
        printf("%4d.", ++kase);

        if (n == 0) {
            cout << " 0\n";
            continue;
        }
        
        if (n / (LL)1e7 > 0) {
            calc(n / (LL)1e7);
            cout << " kuti";
        }
        calc(n % (LL)1e7);
        cout << '\n';
    }
}
