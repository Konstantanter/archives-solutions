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
 
    long long n;
    cin >> n;

    int res = 0;
    while ((1LL << res) < n)
        res++;

    cout << res;
}