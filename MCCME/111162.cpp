#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> a;
    int value;
    while (ss >> value)
        a.push_back(value);

    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = readInts();
    vector<int> b = readInts();

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    cout << res;
}