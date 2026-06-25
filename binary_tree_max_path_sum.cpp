class Solution {
public:

    int answer = INT_MIN;

    int dfs(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left < 0) {
            left = 0;
        }

        if (right < 0) {
            right = 0;
        }

        int currentPath = root->val + left + right;

        if (currentPath > answer) {
            answer = currentPath;
        }

        if (left > right) {
            return root->val + left;
        } else {
            return root->val + right;
        }
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return answer;
    }
};
