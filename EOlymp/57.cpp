#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x1, y1, x2, y2, z2;
    cin >> x1 >> y1 >> x2 >> y2 >> z2;

    cout.precision(3);
    cout << fixed << 1 / hypot(x1 - x2, y1 - y2, z2);
}