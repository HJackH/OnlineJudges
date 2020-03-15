#include <bits/stdc++.h>
using namespace std;

string strA, strB;
int cntA[30], cntB[30];

int main() {
    while (getline(cin, strA) && (getline(cin, strB))) {
        memset(cntA, 0, sizeof(cntA));
        memset(cntB, 0, sizeof(cntB));

        int lenA = strA.length(), lenB = strB.length();
        for (int i = 0; i < lenA; i++) {
            cntA[strA[i] - 'a']++;
        }
        for (int i = 0; i < lenB; i++) {
            cntB[strB[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            int cnt = min(cntA[i], cntB[i]);
            for (int j = 0; j < cnt; j++) {
                cout << (char)('a' + i);
            }
        }
        cout << '\n';
    }
}
