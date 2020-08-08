#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string str;
char table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    IOS
    int n = strlen(table);
    while (getline(cin, str)) {
        for (int i = 0, ed = str.length(); i < ed; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (table[j] == str[i]) {
                    break;
                }
            }
            if (j == n) {
                cout << ' ';
            } else {
                cout << table[j - 1];
            }
        }
        cout << '\n';
    }
}