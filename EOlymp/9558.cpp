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

    int n;
    cin >> n;

    vector<int> fib = { 0, 1 };
    const int MOD = 1e9 + 7;

    for (int i = 2; i <= n; i++)
        fib.push_back((fib[i - 1] + fib[i - 2]) % MOD);

    cout << fib[n] * 2 % MOD;
}