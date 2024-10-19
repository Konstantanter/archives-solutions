#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

bool solve() {
    string pattern, text;
    if (!(cin >> pattern >> pattern >> text))
        return 0;

    vector<int> p = prefixFunction(pattern + " " + text);

    for (int i = 0; i < p.size(); i++)
        if (p[i] == pattern.size())
            cout << i - 2 * pattern.size() << "\n";

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}