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

    vector<int> res = {
        0, 2, 7, 5, 30,
        169, 441, 1872, 7632, 1740,
        93313, 459901, 1358657, 2504881, 13482720,
        25779600, 68468401, 610346880, 1271932200, 327280800
    };

    cout << res[n] << "\n";
}