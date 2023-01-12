#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(4);
    for (int &value : a)
        cin >> value;

    int den;
    cin >> den;

    int res = 0;
    for (int value : a)
        res = max(res, (value + den - 1) / den);

    cout << res;
}