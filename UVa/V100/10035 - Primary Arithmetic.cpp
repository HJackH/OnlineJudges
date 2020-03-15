#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    int lenA, lenB, len, ans;

    while (cin >> a >> b) {
        if (a == "0" && b == "0") {
            break;
        }

        lenA = a.length() - 1;
        lenB = b.length() - 1;
        len = max(lenA, lenB);

        int carry = 0;
        ans = 0;

        for (int i = len; i >= 0; i--) {
            if (lenA >= 0) {
                carry += a[lenA] - '0';
                lenA--;
            }
            if (lenB >= 0) {
                carry += b[lenB] - '0';
                lenB--;
            }

            carry /= 10;
            if (carry) {
                ans++;
            }
        }

        if (ans) {
            cout << ans << ' ';
        } else {
            cout << "No "; 
        }

        if (ans == 1 || !ans) {
            cout << "carry operation." << endl;
        } else {
            cout << "carry operations." << endl;
        }
    }
}
