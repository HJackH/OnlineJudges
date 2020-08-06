#include <iostream>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lowbit(k) (k & -k)

int n;

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << n - lowbit(n) + 1 << ' ' << n + lowbit(n) - 1 << '\n';  
    }
}