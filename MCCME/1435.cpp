#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

bool isDigit(string &s) {
    for (char c : s)
        if (!isdigit(c))
            return 0;
    return 1;
}

bool isIp(string &s) {
    vector<string> tokens = split(s, ".");
    if (tokens.size() != 4)
        return 0;

    for (string &token : tokens)
        if (token.empty() || token.size() > 3 || !isDigit(token) || stoi(token) > 255)
            return 0;

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << isIp(s);
}