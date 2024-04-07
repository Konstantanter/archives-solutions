#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int divisorCount = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisorCount++;
            divisorCount += d * d != n;
        }
    }
    return divisorCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetDivisorCount;
    cin >> targetDivisorCount;

    int res = 1;
    while (getDivisorCount(res) != targetDivisorCount)
        res++;

    cout << res;
}