#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, int aux, int to) {
    if (!n)
        return;

    if (from % 3 + 1 == to) {
        rec(n - 1, from, to, aux);
        cout << n << " " << from << " " << to << "\n";
        rec(n - 1, aux, from, to);
    } else {
        rec(n - 1, from, aux, to);
        cout << n << " " << from << " " << aux << "\n";
        rec(n - 1, to, aux, from);
        cout << n << " " << aux << " " << to << "\n";
        rec(n - 1, from, aux, to);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n, 1, 2, 3);
}