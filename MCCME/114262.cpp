#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> toPostfix(string &s) {
    vector<string> postfix, stack;
    string number;

    for (char c : s) {
        if (isdigit(c)) {
            number += c;
        } else {
            if (!number.empty()) {
                postfix.push_back(number);
                number.clear();
            }

            if (c == '(') {
                stack.push_back(string(1, c));
            } else if (c == ')') {
                while (stack.back() != "(") {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            } else if (!isspace(c)) {
                while (!stack.empty() && stack.back() != "(" && (c == '+' || c == '-' || stack.back() == "*" || stack.back() == "/")) {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(string(1, c));
            }
        }
    }

    if (!number.empty())
        postfix.push_back(number);
    postfix.insert(postfix.end(), stack.rbegin(), stack.rend());

    return postfix;
}

long long eval(const vector<string> &postfix) {
    vector<long long> stack;

    for (const string &token : postfix) {
        if (isdigit(token[0])) {
            stack.push_back(stoll(token));
        } else {
            long long b = stack.back();
            stack.pop_back();
            long long &a = stack.back();

            if (token == "+")
                a += b;
            else if (token == "-")
                a -= b;
            else if (token == "*")
                a *= b;
            else
                a = a / b - (((a < 0) ^ (b < 0)) && (a % b));
        }
    }

    return stack.back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << eval(toPostfix(s));
}