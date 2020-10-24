#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> ord;
vector<string> ans;

int main() { IOS
    int T, first = 1;
    string str;
    stringstream ss;
    
    cin >> T;
    getline(cin, str);
    while (T--) {
        ord.clear();
        ans.clear();
        
        // blank line
        getline(cin, str);
        getline(cin, str);
        ss.clear();
        ss.str(str);

        int tmp;
        while (ss >> tmp) {
            ord.push_back(tmp);
        }
        ans.resize(ord.size());

        getline(cin, str);
        ss.clear();
        ss.str(str);
        for (int i = 0; i < ord.size(); i++) {
            ss >> str;
            ans[ord[i] - 1] = str;
        }

        if (!first) {
            cout << '\n';
        }
        first = 0;
        for (auto s: ans) {
            cout << s << '\n';
        }
    }
}