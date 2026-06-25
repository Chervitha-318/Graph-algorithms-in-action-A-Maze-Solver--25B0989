class Solution {
public:

    bool check(TreeNode* root, long long minimum, long long maximum) {

        if (root == nullptr) {
            return true;
        }

        if (root->val <= minimum || root->val >= maximum) {
            return false;
        }

        bool leftOK = check(root->left, minimum, root->val);
        bool rightOK = check(root->right, root->val, maximum);

        return leftOK && rightOK;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);

    }
};
