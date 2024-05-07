#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int sum(const string &s) {
    if (s == "ADAUniversity")
        return 0;
    return accumulate(s.begin(), s.end(), 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a;
    for (string s; cin >> s; )
        a.push_back(s);

    stable_sort(a.begin(), a.end(), [](const string &lhs, const string &rhs) {
        return sum(lhs) < sum(rhs);
    });

    for (string &s : a)
        cout << s << "\n";
}