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

    long long sum = 0, product = 1;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        product *= value;
    }

    cout << sum << " " << product;
}