class Solution {
public:
    int maximumStrongPairXor(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (abs(a[i] - a[j]) <= min(a[i], a[j]))
                    res = max(res, a[i] ^ a[j]);
        return res;
    }
};