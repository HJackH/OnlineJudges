#include <bits/stdc++.h>
using namespace std;

int n;
char table[256];
string str;
map<string, int> M;

void buildTable() {
    table['A'] = '2';
    table['B'] = '2';
    table['C'] = '2';
    table['D'] = '3';
    table['E'] = '3';
    table['F'] = '3';
    table['G'] = '4';
    table['H'] = '4';
    table['I'] = '4';
    table['J'] = '5';
    table['K'] = '5';
    table['L'] = '5';
    table['M'] = '6';
    table['N'] = '6';
    table['O'] = '6';
    table['P'] = '7';
    table['Q'] = 0;
    table['R'] = '7';
    table['S'] = '7';
    table['T'] = '8';
    table['U'] = '8';
    table['V'] = '8';
    table['W'] = '9';
    table['X'] = '9';
    table['Y'] = '9';
    table['Z'] = 0;
}

int main() {
    buildTable();
    int T;
    cin >> T;
    while (T--) {
        M.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str;
            string tmp = "";
            for (char c : str) {
                if (isalpha(c)) {
                    tmp += table[c];
                } else if (isdigit(c)) {
                    tmp += c;
                }
            }
            tmp.insert(tmp.begin() + 3, '-');
            if (M.count(tmp)) {
                M[tmp]++;
            } else {
                M[tmp] = 1;
            }
        }

        bool print = false;
        for (auto num : M) {
            if (num.second > 1) {
                cout << num.first << ' ' << num.second << '\n';
                print = true;
            }
        }  
        if (!print) {
            cout << "No duplicates.\n";
        }
        if (T) {
            cout << '\n';
        }
    }
}