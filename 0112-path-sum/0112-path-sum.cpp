/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            if (sum + root->val != target)
                return false;
            else
                return true;

        return dfs(root->left, target, sum + root->val) ||
               dfs(root->right, target, sum + root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        return dfs(root, targetSum, 0);
    }
};