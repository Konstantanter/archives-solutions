#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x, y;
    cin >> x >> y;

    if (0 <= x && x <= 1.57 && 0 <= y && y <= sin(x))
        cout << "YES";
    else
        cout << "NO";
}