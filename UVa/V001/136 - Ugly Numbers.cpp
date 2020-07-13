#include <bits/stdc++.h>
using namespace std;

long long tmp, tmp2;
unordered_set<long long> S;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(1);
    for (long long i = 1; i < 1500; i++) {
        long long tmp = pq.top();
        pq.pop();
        tmp2 = tmp * 2;
        if (!S.count(tmp2)) {
            pq.push(tmp2);
            S.insert(tmp2);
        }
        tmp2 = tmp * 3;
        if (!S.count(tmp2)) {
            pq.push(tmp2);
            S.insert(tmp2);
        }
        tmp2 = tmp * 5;
        if (!S.count(tmp2)) {
            pq.push(tmp2);
            S.insert(tmp2);
        }
    }
    cout << "The 1500'th ugly number is " << pq.top() << ".\n";
}