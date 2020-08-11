#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

long long n;

int main() {
    IOS
    while (cin >> n && n) {
        bitset<33> tmp(n);
        string stmp = tmp.to_string();
        cout << "The parity of " << stmp.substr(stmp.find_first_not_of('0')) << " is " << tmp.count() << " (mod 2).\n";
    }
}