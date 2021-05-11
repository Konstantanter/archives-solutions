#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    if (h == w) {
        int n = (h + 1) / 2;
        cout << n * (n + 1) / 2 << "\n";
    } else {
        cout << ((h + 1) / 2) * ((w + 1) / 2) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}