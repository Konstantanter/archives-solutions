#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string fromDec(long long n, int base) {
    static const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n >= base) {
        res += DIGITS[n % base];
        n /= base;
    }
    res += DIGITS[n];
    reverse(res.begin(), res.end());
    return res;
}

int getComplexity(string &s) {
    return s.size() + set<char>(s.begin(), s.end()).size();
}

void solve() {
    int n;
    cin >> n;

    int resBase = 2;
    string resValue = fromDec(n, 2);

    for (int base = 3; base <= 36; base++) {
        string value = fromDec(n, base);
        if (getComplexity(resValue) > getComplexity(value)) {
            resBase = base;
            resValue = value;
        }
    }

    cout << resBase << " " << resValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}