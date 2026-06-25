class Solution {
public:

    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd) {

        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndex = inStart;

        while (rootIndex <= inEnd) {
            if (inorder[rootIndex] == rootValue) {
                break;
            }
            rootIndex++;
        }

        int leftSize = rootIndex - inStart;
        root->left = build(preorder,inorder,preStart + 1,preStart + leftSize,inStart,rootIndex - 1);
        root->right = build(preorder,inorder,preStart + leftSize + 1,preEnd,rootIndex + 1,inEnd);

        return root;
    }
