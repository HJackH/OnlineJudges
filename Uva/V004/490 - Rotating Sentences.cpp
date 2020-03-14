#include <bits/stdc++.h>
using namespace std;

string input[100 + 10];
int cnt = 0, len[100 + 10], mxlen = 0;

int main() {
    while (getline(cin, input[cnt])) {
        len[cnt] = input[cnt].length();
        mxlen = max(mxlen, len[cnt]);
        cnt++;
    }

    for (int i = 0; i < mxlen; i++) {
        for (int j = cnt - 1; j >= 0; j--) {
            if (i < len[j]) {
                cout << input[j][i];
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}
