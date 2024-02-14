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

    string s;
    cin >> s;

    int res = 0;
    bool found = 0;

    for (char c : s) {
        if (c % 2 == 0) {
            res += c - '0';
            found = 1;
        }
    }

    cout << (found ? res : -1);
}