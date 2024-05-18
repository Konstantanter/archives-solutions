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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    int maxValue = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        maxValue = max(maxValue, value);
    }

    cout << maxValue;
}