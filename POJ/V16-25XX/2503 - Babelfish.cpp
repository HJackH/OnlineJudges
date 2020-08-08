#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string s, s2;
map<string, string> M;

int main() {
    IOS
    while (getline(cin, s) && s.length() > 0) {
        stringstream ss(s);
        ss >> s >> s2;
        M[s2] = s;
    }
    while (cin >> s) {
        if (M.count(s)) {
            cout << M[s] << '\n';
        } else {
            cout << "eh\n";
        }
    }
}