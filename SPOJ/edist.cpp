#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int editDistance(string &a, string &b) {
    vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));

    for (int ai = 0; ai <= a.size(); ai++)
        dist[ai][0] = ai;
    for (int bi = 0; bi <= b.size(); bi++)
        dist[0][bi] = bi;

    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1])
                dist[ai][bi] = dist[ai - 1][bi - 1];
            else
                dist[ai][bi] = min(dist[ai - 1][bi - 1], min(dist[ai - 1][bi], dist[ai][bi - 1])) + 1;
        }
    }

    return dist[a.size()][b.size()];
}

void solve() {
    string a, b;
    cin >> a >> b;

    cout << editDistance(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}