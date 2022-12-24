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

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (a[0] * a[1] * a[size - 1] > a[size - 3] * a[size - 2] * a[size - 1])
        cout << a[0] << " " << a[1] << " " << a[size - 1];
    else
        cout << a[size - 3] << " " << a[size - 2] << " " << a[size - 1];
}