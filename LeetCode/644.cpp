class Solution {
    bool can(vector<int> &a, int width, double average) {
        vector<double> p(a.size());
        for (int i = 0; i < a.size(); i++)
            p[i] = a[i] - average;
        partial_sum(p.begin(), p.end(), p.begin());

        if (p[width - 1] >= 0)
            return 1;

        double minP = 0;
        for (int i = width; i < a.size(); i++) {
            minP = min(minP, p[i - width]);
            if (p[i] - minP >= 0)
                return 1;
        }

        return 0;
    }

public:
    double findMaxAverage(vector<int> &a, int width) {
        double l = -2e9, r = 2e9;
        for (int i = 0; i < 100; i++) {
            double m = (l + r) / 2;
            if (can(a, width, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};