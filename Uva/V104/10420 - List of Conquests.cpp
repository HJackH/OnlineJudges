#include <bits/stdc++.h>
using namespace std;

struct Country {
    string name;
    int cnt;

    Country(string s, int c) {
        name = s;
        cnt = c;
    }

    bool operator < (Country const &other) const {
        return name < other.name;
    }
};

int n, k = 0;
string countryTmp, fname;
map<string, int> M;
vector<Country> countries;

int ID(string str) {
    if (M.count(str) == 0) {
        countries.push_back(Country(str, 0));
        M[str] = k++;
    }
    return M[str];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> countryTmp;
        getline(cin, fname);
        countries[ID(countryTmp)].cnt++;
    }
    sort(countries.begin(), countries.end());
    for (int i = 0; i < k; i++) {
        cout << countries[i].name << ' ' << countries[i].cnt << '\n';
    }
}
