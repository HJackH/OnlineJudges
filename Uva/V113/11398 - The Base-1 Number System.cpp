#include <bits/stdc++.h>
using namespace std;

string input;
int len;
char bit;

int main() {
    while (cin >> input && input != "~") {
        if (input.length() == 1) {
            bit = '1';
        } else {
            bit = '0';
        }

        string tmp;
        while (cin >> input && input != "#") {
            len = input.length();

            if (len == 1) {
                bit = '1';
                continue;
            } else if (len == 2){
                bit = '0';
                continue;
            }

            len -= 2;
            for (int i = 0; i < len; i++) {
                tmp += bit;
            }
        }
        bitset<31> b(tmp);
        cout << b.to_ullong() << endl;
    }
}