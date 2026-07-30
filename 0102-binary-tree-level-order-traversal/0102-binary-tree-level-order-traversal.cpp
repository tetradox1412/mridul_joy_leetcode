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
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return max(depth(root->left), depth(root->right)) + 1;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int max_depth = depth(root);

        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans(max_depth);
        if (root != NULL) {
            q.push({root, 0});
            while (!q.empty()) {
                ans[q.front().second].push_back(q.front().first->val);
                if (q.front().first->left != NULL)
                    q.push({q.front().first->left, q.front().second + 1});
                if (q.front().first->right != NULL)
                    q.push({q.front().first->right, q.front().second + 1});
                q.pop();
            }
        }
        return ans;
    }
};