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

    long long n, m;
    cin >> n >> m;

    m--;
    n -= m;
    
    cout << n * n + m << "\n";
}