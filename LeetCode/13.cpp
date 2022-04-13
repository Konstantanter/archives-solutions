class Solution {
public:
    int romanToInt(const string &s) {
        static const vector<pair<string, int>> CODES = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };
        
        int pos = 0, res = 0;
        for (auto &[code, value] : CODES) {
            while (s.substr(pos, code.size()) == code) {
                pos += code.size();
                res += value;
            }
        }
        return res;
    }
};