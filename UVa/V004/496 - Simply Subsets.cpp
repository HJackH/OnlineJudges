#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

vector<int> a, b, v;

int main() { IOS
    int tmp;
    string str;
    stringstream ss;
    while (getline(cin, str)) {
        a.clear();
        b.clear();
        
        ss.clear();
        ss.str(str);
        while (ss >> tmp) {
            a.pb(tmp);
        }

        getline(cin, str);

        ss.clear();
        ss.str(str);
        while (ss >> tmp) {
            b.pb(tmp);
        }

        v.resize(max(a.size() + 1, b.size() + 1));

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n = a.size(), m = b.size();
        int intersect = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin()) - v.begin();

        if (intersect == min(n, m)) {
            if (n > m) {
                cout << "B is a proper subset of A\n";
            } else if (n < m) {
                cout << "A is a proper subset of B\n";
            } else {
                cout << "A equals B\n";
            }
        } else if (intersect) {
            cout << "I'm confused!\n";
        } else {
            cout << "A and B are disjoint\n";
        }
    }
}