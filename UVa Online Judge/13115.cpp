#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> m(size, vector<int>(size));
    for (vector<int> &row : m)
        for (int &x : row)
            cin >> x;

    for (int i = 0; i < size; i++) {
        set<int> seen;
        for (int j = 0; j < size; j++)
            seen.insert(m[i][j]);
        if (seen.size() != size) {
            cout << "no\n";
            return;
        }
    }

    for (int i = 0; i < size; i++) {
        set<int> seen;
        for (int j = 0; j < size; j++)
            seen.insert(m[j][i]);
        if (seen.size() != size) {
            cout << "no\n";
            return;
        }
    }

    int root = sqrt(size);
    for (int i = 0; i < size; i += root) {
        for (int j = 0; j < size; j += root) {
            set<int> seen;
            for (int di = 0; di < root; di++)
                for (int dj = 0; dj < root; dj++)
                    seen.insert(m[i + di][j + dj]);
            if (seen.size() != size) {
                cout << "no\n";
                return;
            }
        }
    }

    cout << "yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}