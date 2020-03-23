#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 50;

long long n, tmp;

int main() {
    while (cin >> n && n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            pq.push(tmp);
        }

        long long t1, t2, sum = 0;
        for (int i = 0; i < n - 1; i++) {
            t1 = pq.top();
            pq.pop();
            t2 = pq.top();
            pq.pop();
            t1 += t2;
            pq.push(t1);
            sum += t1;
        }

        cout << sum << '\n';
    }
}
