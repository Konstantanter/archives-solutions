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

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    int res = -1;
    for (auto &[value, count] : count)
        if (count > 1)
            res = value;

    cout << res;
}