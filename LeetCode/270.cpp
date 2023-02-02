class Solution {
    void rec(TreeNode *n, double target, int &res) {
        if (!n)
            return;
        
        rec(n->left, target, res);
        rec(n->right, target, res);

        if (abs(target - res) > abs(target - n->val))
            res = n->val;
    }

public:
    int closestValue(TreeNode *root, double target) {
        int res = 2.1e9;
        rec(root, target, res);
        return res;
    }
};