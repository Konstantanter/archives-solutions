#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y && x)
                a[y][x] = a[y - 1][x] + a[y][x - 1];
            else
                a[y][x] = 1;
            cout << setw(6) << a[y][x];
        }
        cout << "\n";
    }
}