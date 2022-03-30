#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    int sum = 0, res = 0;
    map<int, int> seenSum = { { 0, 1 } };

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        res += seenSum[sum - 47];
        seenSum[sum]++;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}