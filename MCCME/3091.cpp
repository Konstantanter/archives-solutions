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

    int itemCount, totalWeight;
    cin >> itemCount >> totalWeight;

    vector<int> minItems(totalWeight + 1, 1e9);
    minItems[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = totalWeight; weight >= itemWeight; weight--)
            minItems[weight] = min(minItems[weight], minItems[weight - itemWeight] + 1);
    }

    if (minItems[totalWeight] != 1e9)
        cout << minItems[totalWeight];
    else
        cout << 0;
}