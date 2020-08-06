#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n, k, num;
char mode;

int main() {
    IOS
    while (cin >> n >> k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while (n--) {
            cin >> mode;
            if (mode == 'Q') {
                cout << pq.top() << '\n';
            } else {
                cin >> num;
                if ((int)pq.size() < k) {
                    pq.push(num);
                } else if (pq.top() < num) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
}